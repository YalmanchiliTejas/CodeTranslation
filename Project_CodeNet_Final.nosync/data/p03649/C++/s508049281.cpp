#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main() {
    int N;
    ll ans = 0, s = 0;
    cin >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        s += a[i] / N;
        b[i] = a[i] / N;
        a[i] -= b[i] * N;
    }
    ans = s;
    while (1) {
        ll s1 = 0;
        for (int i = 0; i < N; i++) {
            a[i] += s - b[i];
            s1 += a[i] / N;
            b[i] = a[i] / N;
            a[i] -= b[i] * N;
        }
        s = s1;
        ans += s1;
        if (s1 == 0) break;
    }
    cout << ans << endl;
    return 0;
}