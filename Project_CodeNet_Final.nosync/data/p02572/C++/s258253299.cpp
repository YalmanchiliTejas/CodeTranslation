#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int NMAX = 2e5 + 5;
int n;
long long a[NMAX], sum[NMAX], sol;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = n; i >= 1; i--) {
        sum[i] = (a[i] + sum[i + 1]) % MOD;
    }
    for(int i = 1; i < n; i++) {
        sol = (sol + a[i] * sum[i + 1]) % MOD;
    }
    cout << sol;
    return 0;
}