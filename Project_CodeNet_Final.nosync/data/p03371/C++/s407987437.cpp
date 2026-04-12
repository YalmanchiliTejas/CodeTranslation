#define _GLIBCXX_DEBUG
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans=INF;
    rep(i,max(X,Y)+1){
        chmin(ans,2*C*i+A*max((ll)0,X-i)+B*max((ll)0,Y-i));
    }
    cout << ans << endl;
}