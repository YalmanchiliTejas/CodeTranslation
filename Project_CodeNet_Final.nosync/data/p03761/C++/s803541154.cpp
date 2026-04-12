#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    string S[50];
    rep(i, n) {
        cin >> S[i];
    }
    int d[26];
    rep(i, 26) {
        d[i] = 3000;
    }

    int t = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        rep(i, n) {
            rep(j, S[i].size()) {
                if(S[i][j] == c) {
                    t++;
                }
            }

            d[c - 'a'] = min(d[c - 'a'], t);
            t = 0;
        }
    }

    for(char c = 'a'; c <= 'z'; c++) {
        rep(i, d[c - 'a']) {
            cout << c;
        }
    }

    cout << endl;
    return 0;
}