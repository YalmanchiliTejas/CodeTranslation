/**
 *    author:  Taichicchi
 *    created: 21.09.2020 22:45:50
 **/

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int K;
    cin >> K;

    char s = S[K - 1];

    rep(i, N) {
        if (S[i] != s) {
            S.replace(i, 1, "*");
        }
    }

    cout << S << endl;

    return 0;
}