#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define int long long
using namespace std;

signed main() {
    string s;
    int n;
    int k;
    cin >> n;
    cin >> s;
    cin >> k;
    rep(i, n) {
        if (s[k - 1] == s[i]) {
            cout << s[i];
        } else {
            cout << "*";
        }
    }
    cout << endl;
    return 0;
    
}
