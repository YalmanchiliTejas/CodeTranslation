#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
const ll mod = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        sum += a;
        ans += mod - (a * a % mod);
    }
    sum %= mod;
    ans = ans + (sum * sum) % mod;
    ans %= mod;
    ans = ans * (mod + 1) / 2;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
