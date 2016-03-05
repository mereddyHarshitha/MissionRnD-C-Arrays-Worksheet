
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

int search(int *Arr, int len, int score) {
	int leftIndex = 0;
	int rightIndex = len - 1;
	int midIndex;

	while (1) {
		midIndex = (leftIndex + rightIndex) / 2;

		if (leftIndex == midIndex) {
			if (Arr[midIndex] > score)
				return midIndex;
		}
		if (Arr[midIndex] < score) {
			leftIndex = midIndex + 1;
			if (leftIndex > rightIndex)
				return midIndex += 1;
		}
		else
			rightIndex = midIndex - 1;

	}
}

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	
	int index;

	if (Arr == NULL)
		return NULL;

	if (len < 0)
		return NULL;

	else{
		if (Arr[0] < Arr[len - 1]){
			index = search(Arr, len, score);
			*lessCount = index;

			if (Arr[index] == score)
				*moreCount = len - index - 1;
			else
				*moreCount = len - index;
		}

		else {
			if (Arr[0] < score){
				*lessCount = len;
				*moreCount = 0;
			}
			else if (Arr[0] > score){
				*moreCount = len;
				*lessCount = 0;
			}
			else
				*lessCount = *moreCount = 0;

		}

	}
	
}
