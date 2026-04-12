#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long> d(s + 1);
    static const int MOD = 998244353;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = s - x; j >= 0; j--) {
            d[j + x] += d[j];
            d[j + x] %= MOD;
        }        
        if (x <= s) {
            d[x] += i + 1;
            d[x] %= MOD;
        }
        res += d[s];
        res %= MOD;
    }
    cout << res;

    return 0;
}