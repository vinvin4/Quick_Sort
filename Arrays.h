#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

/*
*Array is filled by random values
*params: int *mass - address, where values located
*	int size - how many values should be generated
*/
void fill_map(int *mass, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 256;
		Sleep(10);
	}
}


/*
*Show all massive in console
*params: int* mass - address, where values located (massive);
*		int size - massive's size; How many values should be showed;
*/
void print_map(int *mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%-4d", *(mass + i));
	}
	printf("\n");
}

/*
*Exchange values
*params: int *a, *b - addresses of values.
*Sequence is not important
*/
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

/*
*Quicksort method
*params: int *mass - massive, where values should be sorted
*	int left, right - area in massive, where should sort.
*/
void fast_sort(int *mass, int left, int right)
{
	if (left >= right) return;
	if ((right - left) == 1) //Massive with two element can be sorted without any extra methods
	{
		if (mass[left] > mass[right])
		{
			swap(mass + left, mass + right);
		}
		return;
	}

	int value = mass[(left + right) / 2];
	int l_hold = left;
	int r_hold = right;

	while (l_hold < r_hold)
	{
		while (mass[l_hold] < value) l_hold++;
		while (mass[r_hold] > value) r_hold--;

		if (l_hold < r_hold)
		{
			swap(mass + l_hold, mass + r_hold);
			l_hold++;
			r_hold--;
			//print_map(mass, N);
		}
	}
	fast_sort(mass, left, r_hold);
	fast_sort(mass, l_hold, right);

}