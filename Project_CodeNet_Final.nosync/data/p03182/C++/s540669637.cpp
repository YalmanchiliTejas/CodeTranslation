#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(auto i = (a); i < (b); i++)
#define iter(it,c) for(auto it = (c).begin(); it != (c).end(); ++it)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = ~(1<<31);
#define fs first
#define sc second
#define pb push_back

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
    return (a % b + b) % b;
}
typedef pair<ll,ii> iii;


struct node {
        node* left = NULL;
        node* right = NULL;
        ll atl, atr, val;
        ll lazy = 0;
        ll mn,mx;
        node(node* l, node* r, ll v, ll al, ll ar) {
                left = l; right = r; val = v;
                atl = al; atr = ar; mn = v; mx = v;
        }
        void lazyupdate(ll l, ll r, ll by) {
                if(lazy != 0) propagate();
                if(l > atr || r < atl) return;
                if(l <= atl && atr <= r) {
                        val += (atr-atl+1)*by;
                        mx += by; mn += by;
                        if(left != NULL) {
                                left->lazy += by;
                                right->lazy += by;
                        }
                        return;
                }
                left->lazyupdate(l,r,by);
                right->lazyupdate(l,r,by);
                mn = min(left->mn, right->mn);
                mx = max(left->mx, right->mx);
                val = left->val+right->val;
        }
        ll lazyquery(ll l, ll r) {
                if(l > atr || r < atl) return 0;
                if(lazy != 0) propagate();
                if(l <= atl && atr <= r) return val;
                return left->lazyquery(l,r)+right->lazyquery(l,r);
        }
        ll lazylowest(ll l, ll r) {
                if(l > atr || r < atl) return INF;
                if(lazy != 0) propagate();
                if(l <= atl && atr <= r) return mn;
                return min(left->lazylowest(l,r), right->lazylowest(l,r));
        }
        ll lazyhighest(ll l, ll r) {
                if(l > atr || r < atl) return 0;
                if(lazy != 0) propagate();
                if(l <= atl && atr <= r) return mx;
                return max(left->lazyhighest(l,r), right->lazyhighest(l,r));
        }
        void propagate() {
                val += (atr-atl+1)*lazy;
                mn += lazy;
                mx += lazy;
                if(left != NULL) {
                        right->lazy += lazy;
                        left->lazy += lazy;
                }
                lazy = 0;
        }
};
node* build(ll l, ll r) {
        if(l > r) return NULL;
        if(l == r) return new node(NULL, NULL, 0, l, r);
        ll m = (l+r)/2;
        node* left = build(l,m);
        node* right = build(m+1,r);
        node* cur = new node(left,right,0,l,r);
        return cur;
}

vii A[200'050];

int main() {
    cin.sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    ll all_sum = 0;
    rep(i,0,m) {
        ll l,r,a;
        cin >> l >> r >> a;
        all_sum += a;
        A[l].pb(ii(r,a));
    }
    vector<ll> DP(n+10,0);
    node* root = build(0,n+10);
    ll ans = 0;
    DP[n+1] = 0;
    for(ll i = n; i >= 0; i--) {

        DP[i] = root->lazylowest(i,n+1);
        for(ll j = 0; j < A[i].size(); j++) {
            root->lazyupdate(A[i][j].fs+1, n+1, A[i][j].sc);
        }
        root->lazyupdate(i,i, DP[i]);
    }
    for(ll i = 0; i <= n; i++) {
        ans = min(ans, DP[i]);
    }
    cout << all_sum-ans << endl;
    return 0;
}

