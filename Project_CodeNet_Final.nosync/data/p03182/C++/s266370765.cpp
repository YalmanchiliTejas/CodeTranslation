#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 3e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n, m;

vector<pll> rem[MAXN];

ll tree[MAXN], t[4*MAXN], lazy[4*MAXN];
ll dp[MAXN];

ll get(int ind){
    ll res = 0;
    for(;ind > 0; ind -= (ind & -ind)){
        res += tree[ind];
    }
    return res;
}
void push(int v){
    t[2*v] += lazy[v];
    t[2*v + 1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v + 1] += lazy[v];
    lazy[v] = 0;
}

void build(int v, int l, int r){
    if(l == r){
        t[v] = -INF;
    }else{
        int m = (l + r)  / 2;
        build(2*v, l, m);
        build(2*v + 1, m + 1, r);
        t[v] = -INF;
    }
}

void upd1(int v, int tl, int tr, int pos, ll val){
    if(tl == tr){
        t[v] = val;
    }else{
        push(v);
        int m = (tl + tr) / 2;
        if(pos <= m)
            upd1(2*v, tl, m, pos, val);
        else upd1(2*v + 1, m + 1, tr, pos, val);
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}

void upd2(int v, int tl, int tr, int l, int r, ll val){
    if(l > r) return;
    if(tl == l && tr == r){
        t[v] += val;
        lazy[v] += val;
    }else{
        push(v);
        int m = (tl + tr) / 2;
        upd2(2*v, tl, m, l, min(m, r), val);
        upd2(2*v + 1, m + 1, tr, max(m + 1, l), r, val);
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}

ll qu(int v, int tl, int tr, int l, int r){
    if(l > r)
        return -INF;
    if(tl == l && tr == r){
        return t[v];
    }else{
        push(v);
        int tm = (tl + tr) / 2;
        ll ans1 = qu(2*v, tl, tm, l, min(r, tm)), ans2 = qu(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
        return max(ans1, ans2);
    }
}

void upd(int ind, ll val){
    for(; ind <= n; ind += (ind & -ind))
        tree[ind] += val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>n>>m;

    for(int i = 0; i < m; i++){
        ll l, r, a;
        cin>>l>>r>>a;
        rem[r].push_back({l, a});
        upd(l, a);
    }
    ll ans = 0;
    build(1, 1, n);
    for(int i = 1; i <= n; i++){
        dp[i] = -INF;
    }
    for(int i = 1; i <= n; i++){
        ll a = get(i);
        ll b = max(0LL, qu(1, 1, n, 1, i - 1));
        dp[i] = max(dp[i], a + b);
        ans = max(ans, dp[i]);
        for(auto j: rem[i]){
            upd(j.ff, -j.ss);
            upd2(1, 1, n, j.ff, n, j.ss);
        }
        upd1(1, 1, n, i, dp[i] - get(i));
    }
    cout<<ans<<endl;

    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}