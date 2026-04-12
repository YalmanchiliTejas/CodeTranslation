#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MAX (101)
#define MOD (1000000007)

using namespace std;

typedef long long ll;

ll n, k;
char s[10];

int main() {
    cin >> n;
    cin >> s;
    cin >> k;
    
    char moji = s[k - 1];
    REP(i, n) {
        if (moji == s[i]) {
            cout << s[i];
        } else {
            cout << "*";
        }
    }
}
