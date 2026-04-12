#include<bits/stdc++.h>
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<long long> vlong;
typedef vector<string> vstring;
#define vpush(a,x) a.push_back(x);
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
const int INF = 1 << 30;
const int mod=1000000007;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
#define stp(x)  setprecision(x)
int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vlong a(n);
  vlong memo(n);
  rep(i,n){
    cin>>a[i];
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1){
      memo[0]=0;
    }
    else{
      memo[n-i-1]=(a[i+1]+memo[n-i-2])%mod;
    }
  }
  ll ans=0;
  rep(i,n){
    ans+=(memo[n-i-1]*a[i])%mod;
    ans=ans%mod;
  }
  cout<<ans<<'\n';
  return(0);
}
