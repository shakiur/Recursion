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

// Print all letter combinations of phone number
void printPhoneCombos(string);

// Calc individual phone permuations
void calcPhoneCombos(string, string, bool[], bool[], int, int, int, int);

char getSingleChar(int, int);

string getCharsByDigit(int);

int main() {
	printPhoneCombos("8675309");
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

void printPhoneCombos(string phone_num){

	string phone_perm;
	int length = phone_perm.length();

	bool num_pos[length];
	bool letter_pos[length];

	// Set both arrays to false
	for (int i = 0; i < length; i++) {
		num_pos[i] = false;
		letter_pos[i] = false;
	}

	calcPhoneCombos(phone_num, phone_perm, num_pos, letter_pos, 0, 0, length, 3);

}

void calcPhoneCombos(	string phone_num, string phone_perm,
						bool num_pos[], bool letter_pos[], 
						int num_index, int letter_index,
						int phone_length, int letter_length) {

	if(num_index == phone_length && letter_index == letter_length) {
		cout << phone_perm << endl;
	}

	

}


char getSingleChar(int num, int pos) {
	string temp = getCharsByDigit(num);

	return temp[pos];
}

string getCharsByDigit(int n){
	switch(n) {
		case 1:
			return "1";
			break;
		case 2:
			return "ABC";
			break;
		case 3:
			return "DEF";
			break;
		case 4:
			return "GHI";
			break;
		case 5:
			return "JKL";
			break;
		case 6:
			return "MNO";
			break;
		case 7:
			return "PRS";
			break;
		case 8:
			return "TUV";
			break;
		case 9:
			return "WXY";
			break;
		case 0:
			return "0";
			break;
	}
}