#include <bits/stdc++.h>
using namespace std;


int main() {
    char c;
    cin >> c;
    vector<char> s={'a','i','u','e','o'};
    bool flag=false;
    for (int i=0;i<5;i++) {
        if (c==s[i]) flag=true;
    }
    if (flag) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}