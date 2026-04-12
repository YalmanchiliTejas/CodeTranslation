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
//const ll mod = 1000000007;

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
int N;

int solve() {
    //cout.precision(10);
    vector<ll> cmph, cmpw;
    cmph.push_back(INF);
    cmph.push_back(-INF);
    cmpw.push_back(INF);
    cmpw.push_back(-INF);
    vector<ll> r(N), l(N), u(N), d(N);
    for(int i = 0; i < N; i++) {
        cin >> l[i] >> u[i] >> r[i] >> d[i];
        cmph.push_back(d[i]);
        cmph.push_back(u[i]);
        cmpw.push_back(l[i]);
        cmpw.push_back(r[i]);
        cmph.push_back(d[i]+1);
        cmph.push_back(u[i]+1);
        cmpw.push_back(l[i]+1);
        cmpw.push_back(r[i]+1);
    }
    sort(cmph.begin(), cmph.end());
    sort(cmpw.begin(), cmpw.end());
    cmph.erase(unique(cmph.begin(), cmph.end()), cmph.end());
    cmpw.erase(unique(cmpw.begin(), cmpw.end()), cmpw.end());
    for(int i = 0; i < N; i++) {
        auto itr = cmph.begin();
        itr = lower_bound(cmpw.begin(), cmpw.end(), l[i]);
        l[i] = itr - cmpw.begin();
        itr = lower_bound(cmpw.begin(), cmpw.end(), r[i]);
        r[i] = itr - cmpw.begin();
        itr = lower_bound(cmph.begin(), cmph.end(), d[i]);
        d[i] = itr - cmph.begin();
        itr = lower_bound(cmph.begin(), cmph.end(), u[i]);
        u[i] = itr - cmph.begin();
    }
    int H = cmph.size();
    int W = cmpw.size();
    /*
    for(auto tmp : cmph) cerr << tmp << " ";
    cerr << endl;
    for(auto tmp : cmpw) cerr << tmp << " ";
    cerr << endl;
    */
    UnionFind uni(H * W);
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            bool ok = true;
            for(int i = 0; i < N; i++) {
                if(l[i] < w and w <= r[i] and h == u[i]) ok = false;
                if(l[i] < w and w <= r[i] and h == d[i]) ok = false;
            }
            //if(ok) cerr << "h: " << h << " " << w << endl;
            if(ok and h + 1 < H) uni.merge(h*W+w, (h+1)*W+w);
            ok = true;
            for(int i = 0; i < N; i++) {
                if(d[i] < h and h <= u[i] and w == l[i]) ok = false;
                if(d[i] < h and h <= u[i] and w == r[i]) ok = false;
            }
            if(ok and w + 1 < W) uni.merge(h*W+w, h*W+w+1);
            //if(ok) cerr << "w: " << h << " " << w << endl;
        }
    }
    ll ans = 0;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            int idx = h*W+w;
            if(uni.root(idx) == idx) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

int main() {
    while(cin >> N) {
        if(N == 0) break;
        solve();
    }
}
