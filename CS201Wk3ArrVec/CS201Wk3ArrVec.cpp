#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void getArray(int a[], int size);
void printArray(int a[], int size);

void getVector(vector<int> v1);
void printVector(vector<int> v1);

void get2DVector(vector<vector<int>>& v1);
void print2DVector(vector<vector<int>>& v1);


int main() {
    //ARRAYS
    int arrSize = 5;
    int arr[5];
    getArray(arr, arrSize);
    printArray(arr, arrSize);

    //1-DIMENSIONAL VECTOR
    vector <int> v1;
    getVector(v1);
    printVector(v1);

    //2-DIMENSIONAL VECTOR
    vector<vector<int>> v2;
    get2DVector(v2);
    print2DVector(v2);

}

//ARRAYS
void getArray(int a[], int size) {
    cout << "Enter " << size << " integer values:\n";
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
}
void printArray(int a[], int size) {
    cout << "Your array is: \n";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}

//1-DIMENSIONAL VECTOR
void getVector(vector<int> v1) {
    int vecSize, value;
    cout << "How many integers do you want to enter? ";
    cin >> vecSize;
    cout << "\nEnter " << vecSize << " integer values:\n";
    for (int i = 0; i < vecSize; i++) {
        cin >> value;
        v1.push_back(value);
    }
}
void printVector(vector<int> v1) {
    cout << "Your 1-D vector is: \n";
    for (int j = 0; j < v1.size(); j++) {
        cout << v1[j] << " ";
    }
    cout << endl;
}

//2-DIMENSIONAL VECTOR
void get2DVector(vector<vector<int>>& v1) {
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile.is_open()) {
        cout << "Could not open file\n";
        return;
    }
    vector<int> tempRow;
    int size, temp;
    inFile >> size;
    for (int i = 0; i < size; i++) {
        tempRow.clear();
        for (int j = 0; j < size; j++) {
            inFile >> temp;
            tempRow.push_back(temp);
        }
        v1.push_back(tempRow);
    }
    inFile.close();
}
void print2DVector(vector<vector<int>>& v1) {
    cout << "Your 2-D vector is: \n";

    for (int i = 0; i < v1[0].size(); i++) {
        for (int j = 0; j < v1[0].size(); j++) {
            cout << v1[i][j] << " ";
        }
        cout << endl;
    }
}
