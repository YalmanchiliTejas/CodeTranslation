#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

string n;
int k, len;

ll notgiri(int p, int K) {
    ll re = 1;
    rep(i, K) re *= (len - p - i) * 9;
    rep(i, K) re /= i + 1;
    return re;
}

ll giri(int p, int K) {
    if(K <= 0) return 1;
    if(p >= len) return 0;
    if(n[p] == '0') return giri(p + 1, K);
    return giri(p + 1, K - 1) + notgiri(p + 1, K - 1) * (n[p] - '1') +
           notgiri(p + 1, K);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    len = n.size();
    cout << giri(0, k) << endl;
}