#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

void input(vector<int>& v, int number) {
    for (int i = 0; i < number; i ++) { 
        int value;
        cin >> value;
        v.push_back(value);
    }   
    sort(v.begin(), v.end());
}

void calc(vector<int> v) {
    int total = 0;
    int average;
    int size = v.size();
    for (int i = 1; i < size - 1; i ++) {
        total += v[i];
    }   
    average = total / (size - 2); 
    cout << average << endl;
}

int main(void) {
    int number;
    cin >> number;
    while (number != 0) {
        vector<int> v(0);
        input(v, number);
        calc(v);
        cin >> number;
    }   
    return 0;
}