#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    long long x; cin >> x;
    vector<long long> v(n+1, 1), p(n+1, 1);
    for (int i = 0; i < n; ++i) {
        v[i+1] += v[i] * 2 + 2;
        p[i+1] += p[i] * 2;
    }
    long long ans = 0;
    while (x > 0 && n > 0) {
        x -= 1;
        if (x > v[n-1]) {
            ans += 1 + p[n-1];
            x -= v[n-1] + 1;
        }
        if (x >= v[n-1]) {
            ans += p[n-1];
            break;
        }
        n--;
    }
    cout << ans << endl;
    return 0; 
}