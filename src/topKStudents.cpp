/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void merge(struct student *students, int leftIndex, int midIndex, int rightIndex){

	struct student *temp;
	int i = leftIndex;
	int j = leftIndex;
	int k = midIndex + 1;
	int m;
	temp = (struct student*)malloc(30 * sizeof(struct student));

	while (j <= midIndex && k <= rightIndex){

		if (students[j].score < students[k].score){

			temp[i].name = students[k].name;
			temp[i].score = students[k].score;
			k++;

		}
		else{
			temp[i].name = students[j].name;
			temp[i].score = students[j].score;
			j++;
		}
		i++;
	}
	if (j <= midIndex){

		for (m = j; m <= midIndex; m++){
			temp[i].name = students[m].name;
			temp[i].score = students[m].score;
			i++;

		}
	}
	else{
		for (m = k; m <= rightIndex; m++){
			temp[i].name = students[m].name;
			temp[i].score = students[m].score;
			i++;

		}
	}
	for (k = leftIndex; k <= rightIndex; k++){
		students[k].name = temp[k].name;
		students[k].score = temp[k].score;
	}
}


void mergeSort(struct student *students, int leftIndex, int rightIndex){

	int midIndex;

	if (leftIndex<rightIndex){

		midIndex = (leftIndex + rightIndex) / 2;
		mergeSort(students, leftIndex, midIndex);
		mergeSort(students, midIndex + 1, rightIndex);

		merge(students, leftIndex, midIndex, rightIndex);
	}
}

struct student ** topKStudents(struct student *students, int len, int K) {
	
	struct student **res = (struct student**)calloc(K, sizeof(struct student));
	int i;

	if (K <= 0)
		return NULL;
	else
		mergeSort(students, 0, len - 1);

	if (K>len){
		for (i = 0; i < len; i++)
			res[i] = &students[i];
	}
	else{
		for (i = 0; i < K; i++)
			res[i] = &students[i];
	}
	return res;
}