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
void calcPhoneCombos(string, string, int, int);

char getSingleChar(char, int);

string getCharsByDigit(char);

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
	int length = phone_num.length();

	calcPhoneCombos(phone_num, phone_perm, 0, length);

}

void calcPhoneCombos(string phone_num, string phone_perm, int position, int length) {

	if(position == length) {
		cout << phone_perm << endl;
	}
	else {
		for(int i = 0; i < 3; i++) {

			char c = getSingleChar(phone_num[position], i);

			phone_perm += c;

			calcPhoneCombos(phone_num, phone_perm, position+1, length);

			phone_perm = phone_perm.substr(0,phone_perm.length()-1);

		}
	}

}


char getSingleChar(char num, int pos) {
	if(num == '0' || num == '1')
		return num;
	else {
		string temp = getCharsByDigit(num);

		return temp[pos];
	}
}

string getCharsByDigit(char n){
	switch(n) {
		case '2':
			return "ABC";
			break;
		case '3':
			return "DEF";
			break;
		case '4':
			return "GHI";
			break;
		case '5':
			return "JKL";
			break;
		case '6':
			return "MNO";
			break;
		case '7':
			return "PRS";
			break;
		case '8':
			return "TUV";
			break;
		case '9':
			return "WXY";
			break;
	}
}