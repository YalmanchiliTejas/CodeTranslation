#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<long long> l[n], r[n];
    for (int i = 1; i < n; i++) {
        int t = i;
        l[i].emplace_back(0);
        r[i].emplace_back(0);
        while (t < n) {
            l[i].emplace_back(l[i].back() + s[t]);
            t += i;
        }
        int q = n-1-i;
        while (q >= 0) {
            r[i].emplace_back(r[i].back() + s[q]);
            q -= i;
        }
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j * i < n; j++) {
            int d = n-1 - j * i;
            if (d == 0) continue;
            int a = d; int b = a-i;
            if (b <= 0) continue;
            if (a % i == 0 && a / i <= j) continue;
            ans = max(ans, l[i][j] + r[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}