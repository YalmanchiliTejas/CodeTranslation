#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <locale>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);

    int n, k;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (s[i] == s[k - 1])
            cout << s[i];
        else
            cout << "*";
    }
    cout << endl;
}