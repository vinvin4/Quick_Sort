#include "Arrays.h"

#define N 20 //Array size

int main()
{
	int mass[N];
	
	fill_map(mass, N);
	print_map(mass, N);

	fast_sort(mass, 0, N - 1);

	print_map(mass, N);

	_getch();
	return 0;
}