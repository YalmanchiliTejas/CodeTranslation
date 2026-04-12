#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define x           first
#define y           second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(2e5) + 7;
const int mod = int(1e9) + 7;
const ll oo = (ll)1e18;

int n;
ll res, x;
vector<ll> s;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> x, s.pb(x);
    while(1) {
        sort(s.begin(), s.end());
        if(s.back() < n) break;
        for(int i = 0; i < n - 1; ++i) s[i] += s[n - 1] / n;
        res += s[n - 1] / n;
        s[n - 1] %= n;
    }
    cout << res;
}
