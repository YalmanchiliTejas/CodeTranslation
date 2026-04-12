#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int left_to_right(string s) {
    int n = s[0]-'0';
    for (int i=0; i<(int)s.length()/2; i++) {
        int right = s[2*i+2]-'0';
        if (s[2*i+1] == '+') {
            n += right;
        }
        else {
            n *= right;
        }
    }
    return n;
}

int multiplication_first(string s) {
    vector<int> terms;
    terms.push_back(s[0]-'0');
    for (int i=0; i<(int)s.length()/2; i++) {
        int right = s[2*i+2]-'0';
        if (s[2*i+1] == '+') {
            terms.push_back(right);
        }
        else {
            terms[terms.size()-1] *= right;
        }
    }
    return accumulate(terms.begin(), terms.end(), 0);
}

int main() {
    string s;
    int n;
    cin >> s >> n;
    if (left_to_right(s) == n) {
        if (multiplication_first(s) == n) {
            cout << "U" << endl;
        }
        else {
            cout << "L" << endl;
        }
    }
    else {
        if (multiplication_first(s) == n) {
            cout << "M" << endl;
        }
        else {
            cout << "I" << endl;
        }
    }
    return 0;
}