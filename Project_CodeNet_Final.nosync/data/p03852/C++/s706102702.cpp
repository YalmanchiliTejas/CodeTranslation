#include <bits/stdc++.h>
using namespace std;

int main(){
    char c;
    cin >> c;
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    if (find(v.begin(), v.end(), c) != v.end()) {
        cout << "vowel" << "\n";
    }
    else {
        cout << "consonant" << "\n";
    }
}