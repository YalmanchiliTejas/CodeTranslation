#include <bits/stdc++.h>
typedef long long ll;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP2(i, a, b) for(int i = a;i <= b;i++)
#define REPR(i, a, b) for(int i = a; i >= b; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define PI 3.14159265358979323846
#define vi vector<int>
#define vll vector<ll>
#define vi2 vector<vector<int>>
#define eb emplace_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
using P = pair<ll,ll>;
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1}, dy[]{1, 0, -1, 0, -1, 1, -1, 1};
#define INT(name) int name;cin >> name;
#define VEC(type,name,n) vector<type> name(n);REP(i,n) cin >> name[i];

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  ll N,X,M;
  cin >> N >> X >> M;
  vector<ll> vec(100010,0);
  vec[X]=0;
  ll loop=1;
  ll preloop=0;
  ll now=X;
  vector<ll> x;
  x.push_back(X);
  REP2(i,1,M){
    now=(now*now)%M;
    if(vec[now]!=0){
      loop=i-vec[now];
      preloop=vec[now];
      break;
    }
    x.push_back(now);
    vec[now]=i;
  }

  ll ans=0;
  if(N<=preloop){
    REP(i,N){
      ans+=x[i];
    }
  }else{
    REP(i,preloop){
      ans+=x[i];
    }
    N-=preloop;
    ll sum=0;
    REP2(i,preloop,preloop+loop-1){
      sum+=x[i];
    }
    ans+=(N/loop)*sum;
    REP2(i,preloop,preloop+(N%loop)-1){
      ans+=x[i];
    }
  }

  // REP(i,6){
  //   cout << x[i] << endl;
  // }
  // cout << preloop << "a" << loop << endl;

  cout << ans << endl;
}
