#include <bits/stdc++.h>
#include <atcoder/all>
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

ll op(ll a, ll b) {
    return max(a, b);
}

const long long INF = 1e18;

ll e() {
    return -INF;
}
ll X, V;

bool f(ll S) {
    return S < V;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

//const ll mod = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    atcoder::segtree<ll, op, e> seg(A);
    for(int q = 0; q < Q; q++) {
        ll T;
        cin >> T;
        if(T == 1) {
            ll X, V;
            cin >> X >> V;
            X--;
            seg.set(X, V);
        }
        if(T == 2) {
            ll L, R;
            cin >> L >> R;
            L--;
            cout << seg.prod(L, R) << endl;
        }
        if(T == 3) {
            cin >> X >> V;
            X--;
            cout << seg.max_right<f>(X) + 1 << endl;
        }
    }
    return 0;
}