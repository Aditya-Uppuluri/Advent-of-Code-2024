#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Function to check if all adjacent differences satisfy the range condition
bool isValidDifference(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        int diff = abs(v[i] - v[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

// Function to check if the vector is safe
bool check(vector<int>& v) {
    if (v.size() < 2) return true; // Single-element or empty reports are safe by default

    // Check for increasing or decreasing order
    if (is_sorted(v.begin(), v.end()) || is_sorted(v.rbegin(), v.rend())) {
        return isValidDifference(v); // Check difference range condition
    }

    return false; // Not sorted in any order
}

int main() {
    ifstream inputFile("/Users/adityauppuluri/Desktop/ip.txt");
    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    int safe = 0;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> numbers;
        int num;

        while (ss >> num) {
            numbers.push_back(num);
        }

        if (check(numbers)) {
            safe++;
        }
    }
    inputFile.close();

    cout << safe << endl;
    return 0;
}
