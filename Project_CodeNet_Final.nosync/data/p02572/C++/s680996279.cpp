#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
constexpr ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

/* modとる */
inline ll modu(ll a){
    return(a % mod + mod) % mod;
}

/* 逆元(法mod = 1e9+7) */
ll modinv(ll a){
    ll b = mod, u = 1, v = 0;
    while (b){
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
        }
    return modu(u);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    ll nijouwa = 0,wa = 0;
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N)cin >> A[i];
    REP(i,N){
        nijouwa += A[i]*A[i];
        wa += A[i];
        nijouwa = modu(nijouwa);
        wa = modu(wa);
    }
    ll sum = modu(wa*wa - nijouwa);
    cout << modu(sum * modinv(2)) << "\n";
}