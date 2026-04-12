#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<char> v;
    v.push_back('a');
    v.push_back('i');
    v.push_back('u');
    v.push_back('e');
    v.push_back('o');
    char c;
    cin >> c;
    if (find(v.begin(), v.end(), c) != v.end()) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}