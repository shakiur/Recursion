#include <iostream>

using namespace std;

// Find integer in array using binary search method
int binarySearch(int[], int, int, int);

int main() {

}

int binarySearch(int array[], int lower, int upper, int target) {

	int mid = ( (upper - lower) / 2 ) + lower;

	if(array[mid] == target) 
		return array[mid];

	else if(target > array[mid]) 
		return binarySearch(array, mid+1, upper, target);

	else 
		return binarySearch(array, lower, mid-1, target);
	
}