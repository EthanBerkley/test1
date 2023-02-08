/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: e450b680
 */
#include <stdio.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int numArr[], float moneyArr[])
{
	for (int i = 0; i < 12; i++)
	{
		int maxInd = i;
		for (int j = i; j < 12; j++)
			if (moneyArr[numArr[j]] > moneyArr[numArr[maxInd]])
				maxInd = j;

		swap(numArr + i, numArr + maxInd);
	}
}

int main()
{
	FILE* in_file = fopen("input.txt", "r");


	char* monthNames[12] = {
			"January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"July",
			"August",
			"September",
			"October",
			"November",
			"December"
	};
	float nums[12];
	int numInds[12];
	for (int i = 0; i < 12; i++)
	{
		numInds[i] = i;
		fscanf(in_file, "%f", nums + i);
	}


	printf("\nMonthly sales report for 2022:\n\n");
	printf("Month\tSales\n");
	printf("January\t%.2f\n", nums[0]);
	printf("February\t%.2f\n", nums[1]);
	printf("March\t%.2f\n", nums[2]);
	printf("April\t%.2f\n", nums[3]);
	printf("May\t%.2f\n", nums[4]);
	printf("June\t%.2f\n", nums[5]);
	printf("July\t%.2f\n", nums[6]);
	printf("August\t%.2f\n", nums[7]);
	printf("September\t%.2f\n", nums[8]);
	printf("October\t%.2f\n", nums[9]);
	printf("November\t%.2f\n", nums[10]);
	printf("December\t%.2f\n", nums[11]);


	sort(numInds, nums);

	printf("Sales summary:\n\n");

	printf("Minimum sales: %.2f (%s)\n",nums[numInds[11]], monthNames[numInds[11]]);
	printf("Maximum sales: %.2f (%s)\n",nums[numInds[0]], monthNames[numInds[0]]);

	float avg = 0;
	for (int i = 0; i < 12; i++)
	{
		avg += nums[i];
	}

	printf("Average sales: %.2f\n\n", avg / 12);
	printf("Six-Month moving average report:\n\n");

	float avgs[7] = {0};

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 7; j++)
		{
			avgs[j] += nums[i + j];
		}
	}

	printf("January-June\t%.2f\n", avgs[0] / 6);
	printf("February-July\t%.2f\n", avgs[1] / 6);
	printf("March-August\t%.2f\n", avgs[2] / 6);
	printf("April-September\t%.2f\n", avgs[3] / 6);
	printf("May-October\t%.2f\n", avgs[4] / 6);
	printf("June-November\t%.2f\n", avgs[5] / 6);
	printf("July-December\t%.2f\n\n", avgs[6] / 6);

	printf("Sales report (highest to lowest):\n\n");
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++)
	{
		printf("%s\t\t$%.2f\n", monthNames[numInds[i]], nums[numInds[i]]);
	}




	return 0;
}
