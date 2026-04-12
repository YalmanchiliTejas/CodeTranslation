#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;  
    cin >> c;
    string str = "aiueo";
    int p = 0;
    for (int i =0; i < str.size(); i++) {
        if (str.at(i) == c) {
            p++;
        }
    }

    if (p==0) {
        cout << "consonant" << endl;
    }else {
        cout << "vowel" << endl;
    }

}