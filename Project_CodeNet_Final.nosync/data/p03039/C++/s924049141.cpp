//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
using namespace std;
using ll=long long;
using ld=long double;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
struct edge{ll to,cost;};
struct edge2{ll from,to,cost;};

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

//組み合わせを線形で
//参考:https://drken1215.hatenablog.com/entry/2018/06/08/210000

const int MXN=1000001;//変更可
ll fac[MXN],inv[MXN],finv[MXN];

void COMinit(int M) {
    fac[0]=fac[1]=1;
    inv[1]=1;
    finv[0]=finv[1]=1;
    for(int i=2;i<MXN;i++){
        fac[i]=fac[i-1]*i%M;
        inv[i]=M-M/i*inv[M%i]%M;
        finv[i]=finv[i-1]*inv[i]%M;
    }
}

ll COMBI(int N,int K,int M){
    if(N<K){
        return 0;
    }
    if(N<0||K<0){
        return 0;
    }
    return fac[N]*finv[N-K]%M*finv[K]%M;
}

ll PERMU(int N,int K,int M){
    if(N<K){
        return 0;
    }
    if(N<0||K<0){
        return 0;
    }
    return fac[N]*finv[N-K]%M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,M,K;
    cin >> N >> M >> K;
    COMinit(MOD);
    ll ans=0;
    rep(d,N){
        ans+=((COMBI(N*M-2,K-2,MOD)*d)%MOD*((N-d)*M*M)%MOD)%MOD;
        ans%=MOD;
    }
    rep(d,M){
        ans+=((COMBI(N*M-2,K-2,MOD)*d)%MOD*((M-d)*N*N)%MOD)%MOD;
        ans%=MOD;
    }
    cout << ans << endl;
}