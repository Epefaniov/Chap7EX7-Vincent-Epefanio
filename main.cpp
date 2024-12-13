/* 
    Assignment: Chapter 7 Excersise 7

    Date: 12/13/2024

    Programmer: Vincent Epefanio

    Reqirements: Write a program that asks the user for a file name. Assume the file contains a series of numbers, each written on a separate line. The program should read the contents of the file into an array then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
To test the program, you can download the file numbers.txt from the book’s companion website.

*/



#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputFile(filename);  

    if (!inputFile) {  
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    vector<int> numbers;  
    int number;

    
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    
    if (numbers.empty()) {
        cerr << "The file is empty or contains no valid numbers." << endl;
        return 1;
    }

    
    int lowest = numeric_limits<int>::max();
    int highest = numeric_limits<int>::min();
    int total = 0;

    for (int num : numbers) {
        if (num < lowest) {
            lowest = num;
        }
        if (num > highest) {
            highest = num;
        }
        total += num;
    }

    double average = static_cast<double>(total) / numbers.size();  

    
    cout << "Lowest number: " << lowest << endl;
    cout << "Highest number: " << highest << endl;
    cout << "Total of numbers: " << total << endl;
    cout << "Average of numbers: " << average << endl;

    return 0;
}
