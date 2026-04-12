#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define OUT(a) cout << (a) << "\n";
#define ll long long
ll MOD = 10e9 + 7;

int main() {
    int n,k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;
    --k;
    REP(i, n) {
        if(s[k] != s[i]) s[i] = '*';
    }
    OUT(s);
    return 0;
}