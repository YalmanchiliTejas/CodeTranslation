#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using P = pair<ll,ll>;
using um = unordered_map<ll,ll>;
#define fl cout<<flush;
#define endl '\n'
template <typename T> inline void prt(T v){cout<<v<<'\n';}
template <typename T> inline bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=(ll)1e9+7;
const ll MOD2=998244353;
const ld pi=3.14159265358979323846;
const ld eps=1e-10;


// mod. m での a の逆元 a^{-1} を計算する
//ただしmとaが互いにその時のみ
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N,0);
    for(ll i=0;i<N;++i)cin>>A[i];
    ll sum=0;
    for(auto p: A){sum+=p;sum%=MOD;}
    sum%=MOD;
    ll sum2=0;
    for(auto p: A){
        sum2+=p*p;
        sum2%=MOD;
    }
    sum=sum*sum%MOD;
    ll ans=sum-sum2+MOD;
    ans%=MOD;
    ans*=modinv(2,MOD);
    ans%=MOD;
    prt(ans);
    

    return 0;
}

