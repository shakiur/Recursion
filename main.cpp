#include <iostream>

using namespace std;

// Find integer in array using binary search method
int binarySearch(int[], int, int, int);

// Print all permutations of string
void printPermutations(string);

void calcPermutations(string, string, int, bool[], int);

// Print all permutations without repeating patterns
void printPermutationsNoRpt(string);

void calcPermutationsNoRpt(string, string, int, int);

int main() {
	printPermutationsNoRpt("wxyz");
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

void printPermutations(string str) {
	int str_len = str.length();
	string str_perm;

	bool hold_arr[str_len];

	// Set array to false
	for(int i = 0; i < str_len; i++) {
		hold_arr[i] = false;
	}

	calcPermutations(str, str_perm, str_len, hold_arr, 0);

}

void calcPermutations(	string str, 
						string str_perm, 
						int str_len, 
						bool hold_array[], 
						int place) {

	if(place == str_len){
		cout << str_perm << ": FULL PERM FOUND" << endl << endl;	
	}
	else {

		for(int i = 0; i < str_len; i++) {
		
			if(!hold_array[i]) {

				str_perm += str[i];
				hold_array[i] = true;
				cout << str_perm << endl;

				calcPermutations(str, str_perm, 
								 str_len, hold_array,
								 place+1);

				hold_array[i] = false;

				str_perm = str_perm.substr(0,str_perm.length()-1);
				
			}

		}

	}

}

void printPermutationsNoRpt(string str) {

	int str_len = str.length();
	string str_perm;

	calcPermutationsNoRpt(str, str_perm, str_len, 0);

}

void calcPermutationsNoRpt(	string str, 
							string str_perm, 
							int str_len, 
							int str_start){

	for(int i = str_start; i < str_len; i++) {
		str_perm += str[i];
		cout << str_perm << endl;

		if(i < str_len - 1) {
			calcPermutationsNoRpt(str, str_perm, str_len, i+1);
		}

		str_perm = str_perm.substr(0,str_perm.length()-1);
	}

}