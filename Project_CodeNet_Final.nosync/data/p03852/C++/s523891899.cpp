#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //string c;
    char c;
    cin >> c;
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}