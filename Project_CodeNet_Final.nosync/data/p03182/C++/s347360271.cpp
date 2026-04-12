#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

template<class Val, class Cmp, long long Inv>
struct StarrySkyTree {
    StarrySkyTree() {}
    StarrySkyTree(int n_) {
        for (n = 1; n < n_; n <<= 1);
        data = datb = vector<Val>(n << 1);
    }
    void add(int L, int R, Val x, int l, int r, int k) {
        if (L <= l && r <= R) {
            data[k] += x;
        } else if (l < R && L < r) {
            int mid = (l + r) >> 1;
            add(L, R, x, l, mid, (k << 1) + 1);
            add(L, R, x, mid, r, (k << 1) + 2);
            Val a = data[(k << 1) + 1] + datb[(k << 1) + 1];
            Val b = data[(k << 1) + 2] + datb[(k << 1) + 2];
            datb[k] = cmp(a, b) ? a : b;
        }
    }
    void add(int L, int R, Val x) {
        add(L, R, x, 0, n, 0);
    }
    Val query(int L, int R, int l, int r, int k) {
        if (L <= l && r <= R) {
            return data[k] + datb[k];
        } else if (l < R && L < r) {
            int mid = (l + r) >> 1;
            Val a = query(L, R, l, mid, (k << 1) + 1);
            Val b = query(L, R, mid, r, (k << 1) + 2);
            Val res = (cmp(a, b) ? a : b) + data[k];
            return res;
        } else {
            return Inv;
        }
    }
    Val query(int L, int R) {
        return query(L, R, 0, n, 0);
    }
    int n;
    vector<Val> data, datb;
    Cmp cmp;
};
using SSTMin32 = StarrySkyTree<int, less_equal<int>, INT_MAX / 3>;
using SSTMax32 = StarrySkyTree<int, greater_equal<int>, INT_MIN / 3>;
using SSTMin64 = StarrySkyTree<long long, less_equal<long long>, LLONG_MAX / 3>;
using SSTMax64 = StarrySkyTree<long long, greater_equal<long long>, LLONG_MIN / 3>;


void solve() {
    int N, M;
    cin >> N >> M;
    
    const int NN = 200005;
    static vector<pii> I[NN], O[NN];
    rep(i, M) {
        int l, r, a;
        cin >> l >> r >> a;
        I[l].emplace_back(r, a);
        O[r].emplace_back(l, a);
    }

    ll ans = 0;
    SSTMax64 sst(N + 1);
    for (int i = 1; i <= N; ++i) {
        each(p, I[i]) {
            sst.add(0, i, p.second);
        }

        ll x = sst.query(0, i);
        smax(ans, x);
        sst.add(i, i + 1, x);

        each(p, O[i]) {
            sst.add(0, p.first, -p.second);
        }
    }

    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}