/**
 *    author:  FromDihPout
 *    created: 2020-09-01
**/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mult(int a, int b) {
    return (int) ((long long) a * b % MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<long long> suff(n);
    suff[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        suff[i] = suff[i+1] + a[i];
        suff[i] %= MOD;
    }
    
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += mult(a[i], suff[i+1]);
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}