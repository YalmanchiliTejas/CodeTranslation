#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 2e2;

int main() {

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> pref(n+1);
    for (int i = n - 1; i >= 0; i--) {
        pref[i] = pref[i+1] + a[i];
        pref[i] %= MOD;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long x = (a[i] * (pref[i + 1]));
        x %= MOD;
        ans += x;
    }
    /*
    long long ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans2 += (a[i] * a[j]);
            ans2 %= MOD;
        }
    }*/
    cout << (ans % MOD) << endl;
    //cout << ans2 << endl;

    return 0;
}