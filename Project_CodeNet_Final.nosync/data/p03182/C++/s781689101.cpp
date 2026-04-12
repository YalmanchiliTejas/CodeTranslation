#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

template < typename T > 
struct RAQandRMQ {
    int n;
    vector<T> data, lazy;

    RAQandRMQ(int sz) {
        n=1;
        while (n < sz) n <<= 1;
        data.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);

        data[n - 1] = 0;
        for (int i=n-2; i>=0; i--) data[i] = max(data[2*i+1], data[2*i+2]);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            data[k] += lazy[k];
            if (r-l>1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, T x, int k=0, int l=0, int r=-1) {
        if (r<0) r = n;
        eval(k, l, r);
        if (b<=l || r <=a) return;
        if (a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        } else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = max(data[2*k+1], data[2*k+2]);
        }
    }

    T getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if (r<0) r=n;
        if (b<=l || r<=a) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        T vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

    T operator[](int i) {
        return data[i + n - 1];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    V< V< P<int, int> > > la(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r, a; cin >> l >> r >> a;
        la[r].emplace_back(l, a);
    }
    
    RAQandRMQ<ll> lseg(n + 1);
    for (int i = 1; i <= n; i++) {
        ll maxd = lseg.getmax(0, i);
        lseg.add(i, i + 1, maxd);
        for (P<int, int> lll: la[i]) {
            // cout << "maxd: " << maxd << '\n';
            lseg.add(lll.first, i + 1, lll.second);
            // cerr << "lseg.lazy: ";
            // DEBUG_VLL(lseg.lazy)
            // cerr << "lseg.data: ";
            // DEBUG_VLL(lseg.data)
        }
    }
    cout << lseg.getmax(0, n + 1) << '\n';
    return 0;
}
