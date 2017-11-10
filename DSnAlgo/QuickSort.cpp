#include <stdio.h>
#include <random>
#define N 100

void print(int* d) {
	for (int i = 0; i < N; i++) {
		printf("%d ", d[i]);
	}
	printf("\n");
}

void quickSort(int* d, int start, int end) {
	if (start >= end) return;

	int left = start;
	int right = end;
	while (left <= right) {
		int pivotValue = d[left + (right - left) / 2];
		while (pivotValue > d[left]) left++;
		while (pivotValue < d[right]) right--;
		if (left <= right) {
			// swap
			int tmp = d[left];
			d[left] = d[right];
			d[right] = tmp;
			left++, right--;
		}

		if (left < end) {
			quickSort(d, left, end);
		}
		if (right > start) {
			quickSort(d, start, right);
		}
	}

}

bool isSorted(int* d) {
	int prev = d[0];
	for (int i = 1; i < N; i++) {
		if (prev > d[i]) {
			return false;
		}
		prev = d[i];
	}
	return true;
}

int main() {
	int data[N];

	// Generate random numbers
	for (int i = 0; i < N; i++) {
		data[i] = rand();
	}

	// Print original data
	printf("Before: \n");
	print(data);

	// Sort data
	quickSort(data, 0, N - 1);

	// Print new result
	printf("After: \n");
	print(data);

	// Check if sorted
	printf("Is sorted: %s\n", isSorted(data) ? "TRUE" : "FALSE");

	printf("Done.\n");
	return 0;
}