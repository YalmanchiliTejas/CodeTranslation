//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
#define pb push_back
using namespace std;
using ll=long long;
using ld=long double;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<char> vc;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vl acc(N+1);
    vl A(N);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,N){
        acc[i+1]=acc[i]+A[i];
        acc[i+1]%=MOD;
    }
    ll ans=0;
    rep(i,N){
        ans+=A[i]*acc[i];
        ans%=MOD;
    }
    cout << ans << endl;
}
/*
overflow checked?
corner case checked?
boundary checked?
not TLE in worst case checked?
*/