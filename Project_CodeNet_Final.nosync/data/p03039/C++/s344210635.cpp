#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<vector<ll>> VV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define rep(i, n) REP(i, 0, n)
const int INF=1e9;
const int MAX=100005;
const int MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#define dbgmap(mp) for (auto i = mp.begin(); i != mp.end(); ++i) { cout << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,n){cout<<arr[i][j]<<" ";}cout<<endl;}
#define sum(v) accumulate(ALL(v),0)
#define fi first
#define se second

template<typename T1, typename T2>
ostream &operator<<(ostream &s, const pair<T1, T2> &p) { return s<<"("<<p.first<<", "<<p.second<<")"; }

// vector
template<typename T>
ostream &operator<<(ostream &s, const vector<T> &v) {
    int len=v.size();
    for(int i=0; i<len; ++i) {
        s<<v[i];
        if(i<len-1) s<<"	";
    }
    return s;
}

// 2 dimentional vector
template<typename T>
ostream &operator<<(ostream &s, const vector<vector<T> > &vv) {
    int len=vv.size();
    for(int i=0; i<len; ++i) {
        s<<vv[i]<<endl;
    }
    return s;
}

// mod. m での a の逆元 a^{-1} を計算する
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll ncm(ll n,ll m){
    ll ans = 1;
    rep(x,m){
        ans *= (n-x);
        ans %= MOD;
        ans *= modinv(m-x,MOD);
        ans %= MOD;
    }
    return  ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans = 0;
    ll ansX = 0;
    ll ansY = 0;
    //X
    REP(d,1,n){
        ansX += (d*(n-d))%MOD;
    }
    ansX *= m*m;
    ansX %= MOD;
    
    //Y

    REP(d,1,m){
        ansY += (d*(m-d))%MOD;
    }
    ansY *= n*n;
    ansY %= MOD;
    
    ans = ansX+ansY;

    if(k>2){
        ans *= ncm(n*m-2,k-2);
        ans %= MOD;
    }
    
    cout<<ans<<endl;
    return  0;
}
