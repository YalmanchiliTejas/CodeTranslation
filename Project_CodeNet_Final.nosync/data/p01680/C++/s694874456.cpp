#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
const ll mod = 1000000007;
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};

ll beki[200000];
int main() {
    ll N, M;
    beki[0] = 1;
    for(ll i = 1; i <= 1e5; i++) {
        beki[i] = beki[i-1] * 2 % mod;
    }
    while(cin >> N >> M) {
        if(N == 0) break;
        UnionFind uni(N);
        set<ll> st;
        while(M--) {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            uni.merge(a, b);
        }
        ll ans = 0;
        ll num = 0;
        bool two = false;
        for(int i = 0; i < N; i++) {
            if(uni.root(i) != i) continue;
            num++;
            if(uni.size(i) >= 2) two = true;
        }
        ans = beki[num];
        if(two) ans++;
        ans %= mod;
        cout << ans << endl;
    }
    return 0;
}
