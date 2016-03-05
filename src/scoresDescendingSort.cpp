/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
	char name[10];
	int score;
};

void decMerge(struct student *students, int leftIndex, int midIndex, int rightIndex){

	struct student *temp;
	int i = leftIndex;
	int j = leftIndex;
	int k = midIndex + 1;
	int m, p;
	temp = (struct student*)malloc(30 * sizeof(struct student));

	while (j <= midIndex && k <= rightIndex){

		if (students[j].score < students[k].score){

			for (p = 0; students[k].name[p] != '\0'; p++){
				temp[i].name[p] = students[k].name[p];
			}
			temp[i].name[p] = '\0';
			temp[i].score = students[k].score;
			k++;

		}
		else{

			for (p = 0; students[j].name[p] != '\0'; p++){
				temp[i].name[p] = students[j].name[p];
			}
			temp[i].name[p] = '\0';
			temp[i].score = students[j].score;
			j++;
		}
		i++;
	}
	if (j <= midIndex){

		for (m = j; m <= midIndex; m++){

			for (p = 0; students[m].name[p] != '\0'; p++){
				temp[i].name[p] = students[m].name[p];
			}
			temp[i].name[p] = '\0';
			temp[i].score = students[m].score;
			i++;

		}
	}
	else{
		for (m = k; m <= rightIndex; m++){

			for (p = 0; students[m].name[p] != '\0'; p++){
				temp[i].name[p] = students[m].name[p];
			}
			temp[i].name[p] = '\0';
			temp[i].score = students[m].score;
			i++;

		}
	}
	for (k = leftIndex; k <= rightIndex; k++){

		for (p = 0; temp[k].name[p] != '\0'; p++){
			students[k].name[p] = temp[k].name[p];
		}
		students[k].name[p] = '\0';
		students[k].score = temp[k].score;
	}
}

void decMergeSort(struct student *students, int leftIndex, int rightIndex){

	int midIndex;

	if (leftIndex<rightIndex){

		midIndex = (leftIndex + rightIndex) / 2;
		decMergeSort(students, leftIndex, midIndex);
		decMergeSort(students, midIndex + 1, rightIndex);
		decMerge(students, leftIndex, midIndex, rightIndex);
	}
}

void * scoresDescendingSort(struct student *students, int len) {
	
	if (students == NULL)
		return NULL;

	if (len < 0)
		return NULL;

	else
		decMergeSort(students, 0, len - 1);

}