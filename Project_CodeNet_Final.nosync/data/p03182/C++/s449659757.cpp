#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

using namespace std;

/*
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
*/

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<long long, long long> pll;
typedef vector<pll> vpll;

typedef long double ld;
typedef vector<ld> vld;

typedef vector<bool> vb;

/*
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, n) for (ll i = 1; i <= (n); i++)
#define rrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rreps(i, n) for (ll i = (n); i >= 1; i--)
#define all(v) (v).begin(), (v).end()
*/

template <class T> void chmin(T& a, T& b) { a = min(a, b);}
template <class T> void chmax(T& a, T& b) { a = max(a, b);}

constexpr int INF = 1 << 30;
constexpr ll INFL = 1LL << 60;
constexpr ll MOD = 1000000007;
constexpr ld EPS = 1e-9;

struct SegTree {
    int n;
    vll data;
    vll lazy;

    SegTree(int m) {
        n = 1;
        while(n < m) n *= 2;
        data = vll(2 * this->n - 1, 0);
        lazy = vll(2 * this->n - 1, 0);
    }

    void eval(int k) {
        if(lazy[k] == 0) return;
        if(k < n - 1) {
            lazy[k * 2 + 1] += lazy[k];
            lazy[k * 2 + 2] += lazy[k];
        }
        data[k] += lazy[k];
        lazy[k] = 0;
    }

    void update(int a, int b, ll x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k);
        }
        else if(a < r && l < b) {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    void update(int a, int b, ll x) {
        update(a, b, x, 0, 0, n);
    }

    ll query(int a, int b, int k, int l, int r) {
        eval(k);
        if(r <= a || b <= l) {
            return -INFL;
        }
        if(a <= l && r <= b) {
            return data[k];
        }
        else {
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }

    ll query(int a, int b) {
        return query(a, b, 0, 0, n);   // query for [a, b)
    }
};

typedef tuple<ll, ll, ll> tup;
void solve() {
    ll n, m;
    cin >> n >> m;

    priority_queue<pll, vpll, greater<pll>> add;
    priority_queue<tup, vector<tup>, greater<tup>> del;
    int rmax = 0;
    for(ll i = 0; i < m; i++) {
        ll l, r, a;
        cin >> l >> r >> a;
        add.push(make_pair(l, a));
        del.push(make_tuple(r, l, a));
    }

//    const int nmax = 200010;
    SegTree st(n + 1);
//    SegTree st(nmax);
    for(ll i = 1; i <= n + 1; i++) {
//    for(ll i = 1; i <= nmax - 1; i++) {
        while(!add.empty() && add.top().first <= i) {
            pll p = add.top();
            add.pop();
            st.update(0, p.first, p.second);
        }
        while(!del.empty() && get<0>(del.top()) < i) {
            ll r, l, a;
            tie(r, l, a) = del.top();
            del.pop();
            st.update(0, l, -a);
        }
        st.update(i, i + 1, st.query(0, i));
    }
    cout << st.query(0, n + 2) << endl;
    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
