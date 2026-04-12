#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

vector<P> d;

//RMQ
struct SegTree {
    int N;
    vector<int> dat;
    SegTree() {}
    SegTree(int n) {
        N = 1;
        while(N < n) N *= 2;
        dat.resize(2 * N, INF);
        // for(int i = 0; i < 2*N-1; i++)
        //     dat[i] = INF;
    }
    // update k th element
    void update(int k, int a) {
        k += N-1; // leaf
        dat[k] = a; 
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    // min [a, b)
    int query(int a, int b) { return query(a, b, 0, 0, N); }
    int query(int a, int b, int k, int l, int r) {
        if(r <= a or b <= l) return INF;
        if(a <= l and r <= b) return dat[k];
        int m = (l + r) / 2;
        return min(query(a, b, k*2+1, l, m), query(a, b, k*2+2, m, r));
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        if(x[i] > y[i]) swap(x[i], y[i]);
        d. push_back(P(x[i], y[i]));
    }
    SegTree r(n), r2(n);
    sort(all(d));
    rep(i, 0, n){
        r.update(i, -d[i].second);
        r2.update(i, d[i].second);
    }
    int rMIN = 1e12, rMAX = 0, bMIN = 1e12, bMAX = 0;
    rep(i, 0, n){
        chmax(rMAX, x[i]);
        chmin(rMIN, x[i]);
        chmax(bMAX, y[i]);
        chmin(bMIN, y[i]);
    }
    int ans = (rMAX - rMIN) * (bMAX - bMIN);
    // cout << rMAX << " " << rMIN << " " << bMAX << " " << bMIN << endl;
    rep(i, 1, n){
        rMIN = d[i].first;
        rMAX = max(d[n - 1].first, -r.query(0, i));
        int cMIN = r2.query(0, i);
        if(cMIN < rMIN){
            chmax(rMAX, rMIN);            
            rMIN = cMIN;
        }
        bMIN = d[0].first;
        bMAX = -r.query(i, n);
        // cout << rMAX << " " << rMIN << " " << bMAX << " " << bMIN << endl;
        chmin(ans, (rMAX - rMIN) * (bMAX - bMIN));
    }
    cout << ans << endl; 
}