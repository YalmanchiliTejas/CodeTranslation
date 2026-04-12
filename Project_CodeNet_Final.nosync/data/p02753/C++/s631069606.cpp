#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    string S;
    cin >> S;

    bool yes = false;
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] != S[i + 1]) {
            yes = true;
            break;
        }
    }
    if (yes)
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
    return 0;
}