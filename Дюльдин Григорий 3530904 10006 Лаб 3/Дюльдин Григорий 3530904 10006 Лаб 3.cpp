#include <iostream>
#include <ctime>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <cstdlib> // for exit function
// This program reads values from the file 'example.txt'
// and echoes them to the display until a negative value
// is read.
int arr[100];
int input;
int arrlen, arrsize;

void shift(int x, int y, int *arr) {
	int len = x;
	int count = y;
	while (count > 0) {

		int temp = arr[len - 1];
		for (int i = len - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = temp;
		count--;
	}
}

void printArr(int* arr, int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
int main()
{
	cout << "How much do you want to shift to the right?: ";

	std::cin >> input;

	if (input < 0 || !input) {
		cerr << "This input is incorrect, please write a number greater or equal than 0 and that is not a letter" << endl; //check input for legibility
		return -1;
	}

	ifstream indata; // indata is like cin
	int num; // variable for input value
	indata.open("example.txt"); // opens the file

	if (!indata) { // file couldn't be opened
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}

	indata >> num;   // indata inserts data from file to the 'num' variable, 
	int i;        
	arrlen = num;

	for (i = 0; indata.eof() != true; i++) { // keep reading until end-of-file
		indata >> arr[i];
	}
	printArr(arr, arrlen); // function for printing
	cout << endl;
	shift(arrlen, input, arr); // function for shifting
	printArr(arr, arrlen);
	indata.close();


	cout << endl;
	cout << "-----------------------" << endl;
	cout << "-----------------------" << endl;
	cout << "-----------------------" << endl;


	int const arrlenstat = 10;
	int array[arrlenstat] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //static array
	cout << "This is the array before: \n";
	cout << "It will be shifted by " << input << endl;
	printArr(array, arrlenstat); // printing function call
	cout << endl;
	shift(arrlenstat, input, array); // call for shift function 
	cout << endl;
	cout << "It has been shifted: \n";
	printArr(array, arrlenstat);  // call print function with parameters 'array' and 'arrlenstat'

	cout << endl;
	cout << endl;
	cout << "-----------------------" << endl;
	cout << "-----------------------" << endl;
	cout << "-----------------------" << endl;
	cout << endl;

	cout << "How big do you want your array to be?: ";
	std::cin >> arrlen;
	srand((unsigned)time(0)); //random number generator with null seed


	for (int i = 0; i < arrlen; i++) {
		array[i] = (rand() % 10);      // for loop inserts random nums into array
	}

	for (int i = 0; i < arrlen; i++) {
		cout << "Elements no " << i + 1 << "::" << array[i] << endl;
	}

	shift(arrlen, input, array);
	printArr(array, arrlen);
	return 0;
}