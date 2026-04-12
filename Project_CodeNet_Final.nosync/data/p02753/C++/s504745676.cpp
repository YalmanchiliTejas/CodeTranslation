//
// Created by user on 3/9/2020.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    bool A = false, B = false;
    for (int i = 0; i < 3; ++i) {
        if (s[i] == 'A') A = true;
        else B = true;
    }
    if (A == true and B == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}