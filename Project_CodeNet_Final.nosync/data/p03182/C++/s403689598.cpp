#include <bits/stdc++.h>
#define foi(i,k,n) for(int i = (int)k; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAXM = 5 + 200000;
const ll INF = 1LL << 60;

struct st {
    int tam;
    vector<ll> tree;
    vector<ll> lazy;
    st(int n) {
        tam = n;
        tree.assign(tam << 2, 0LL);
        lazy.assign(tam << 2, 0LL);
    }
    ll lazy_query(int low, int high, int pos, int& qlow, int& qhigh) {
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        if(lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if(low != high) {
              lazy[left] += lazy[pos];
              lazy[right] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if (qhigh < low || qlow > high)
            return -INF;
        if (low >= qlow && high <= qhigh)
            return tree[pos];
        ll l = lazy_query(low, mid, left, qlow, qhigh);
        ll r = lazy_query(mid + 1, high, right, qlow, qhigh);
        return max(l, r);
    }
    ll query(int i, int j) {
        return lazy_query(0, tam - 1, 0, i, j);
    }
    void lazy_update(int low, int high, int pos, int& qlow, int& qhigh, ll& cant) {
        int mid = (low + high) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        if(lazy[pos] != 0) {
            tree[pos] += lazy[pos];
            if(low != high) {
              lazy[left] += lazy[pos];
              lazy[right] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        if(low > qhigh || high < qlow)    return;
        if(low >= qlow && high <= qhigh) {
            tree[pos] += cant;
            if(low != high) {
              lazy[left] += cant;
              lazy[right] += cant;
            }
            return;
        }
        lazy_update(low, mid, left, qlow, qhigh, cant);
        lazy_update(mid + 1, high, right, qlow, qhigh, cant);
        tree[pos] = max(tree[left], tree[right]);
    }
    void update(int i, int j, ll x) {
        lazy_update(0, tam - 1, 0, i, j, x);
    }};


struct Point {
    int l,r,a;
} p[MAXM];

vector<int> sr[MAXM];
int N,M;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    foi(i,0,M) {
        cin >> p[i].l >> p[i].r >> p[i].a;
        sr[p[i].l].push_back(i);
        sr[1 + p[i].r].push_back(i);
    }
    ll ans = 0LL;
    st s(5+MAXM);
    for(int i = 1; i <= N; ++i) {
        for(int x : sr[i]) {
            if(p[x].l == i) {
                s.update(0, p[x].l - 1, p[x].a);
            } else {
                s.update(0, p[x].l - 1, -p[x].a);
            }
        }
        ll q = s.query(0, i - 1);
        ans = max(ans, q);
        s.update(i,i,q);
    }
    cout << ans << '\n';
    return 0;
}
