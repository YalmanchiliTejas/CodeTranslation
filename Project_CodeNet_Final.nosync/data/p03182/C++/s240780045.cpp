#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 2e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)4e18 + 5;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

inline int add(int a, int b){
    int ans = a + b;
    if(ans >= mod) ans -= mod;
    return ans; 
}

// credits : codeforces :https://codeforces.com/blog/entry/54396
bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

ll fast_pow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

struct seg_tree{
    vector<ll> seg;
    vector<ll> lzy;
    int n;

    seg_tree(int x) : n(x){
        seg.resize(4*n+5);
        lzy.resize(4*n+5);
    } 

    void update_lzy(int l, int r, int i){
        if(!lzy[i]) return;
        seg[i] += lzy[i];
        if(l != r) lzy[i*2+1] += lzy[i], lzy[i*2+2] += lzy[i];
        lzy[i] = 0;
    }

    void update(int x, int y, ll val, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);
        if(r < x || l > y) return; 
        if(l >= x && r <= y){
            lzy[i] += val;
            return update_lzy(l, r, i);
        }
        int m = (l+r) >> 1;
        update(x, y, val, l, m, i*2+1);
        update(x, y, val, m+1, r, i*2+2);
        seg[i] = min(seg[i*2+1], seg[i*2+2]);
    }

    ll query(int x, int y, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);
        if(r < x || l > y) return INF;
        if(l >= x && r <= y) return seg[i];
        int m = (l+r) >> 1;
        ll ans = min(query(x, y, l, m, i*2+1), query(x, y, m+1, r, i*2+2));
        return ans;
    }
};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    ll total = 0;
    vector<pii> rgt[n+2];
    for(int j = 0; j < m; j++){
        int l, r, val;
        cin >> l >> r >> val;
        total += val;
        rgt[r].pb({l, val});
    }
    seg_tree seg(n+2);
    for(int j = 1; j <= n; j++){
        // put a '1' here
        ll prv_1 = seg.query(0, j-1);
        seg.update(j, j, prv_1);

        // put a '0' here
        for(auto i : rgt[j]){
            ll l = i.F, val = i.S;
            seg.update(0, l-1, val);
        }
    }
    cout << (total - seg.query(0, n)) << endl;
    return 0;
}
