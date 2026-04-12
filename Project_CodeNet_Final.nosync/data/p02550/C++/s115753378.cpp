#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> mod(m, -1);
    vector<ll> s;
    x = x % m;
    mod[x] = 0;
    s.push_back(0);
    s.push_back(x);
    ll sum = x;
    ll cir, pr;
    for (int i = 1; i < n; i++) {
        ll t = x * x;
        t = t % m;
        x = t;
        if (mod[t] != -1) {
            cir = i - mod[t];
            pr = mod[t];
            ll cirs = s[i] - s[pr];
            sum += ((n - i) / cir) * cirs;
            sum += s[((n - i) % cir) + pr] - s[pr];
            break;
        } else {
            sum += t;
            s.push_back(sum);
            mod[t] = i;
        }
    }
    cout << sum << endl;
}