#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ii {
    ll a, b;
    bool operator < (ii o) const {
        return tie(a, b) < tie(o.a, o.b);
    }
};
struct iii {
    ll a, b, c;
    bool operator < (iii o) const {
        return tie(a, b, c) < tie(o.a, o.b, o.c);
    }
};

const ll MOD = 1000000007;
const ll INF = 1000000000;
const ll MAXN = 1000005;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll N;
    cin >> N;
    ll sum = 0;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll A;
        cin >> A;
        ans = (ans + sum*A) % MOD;
        sum = (sum + A)%MOD;
    }
    cout << ans << "\n";
    
}
