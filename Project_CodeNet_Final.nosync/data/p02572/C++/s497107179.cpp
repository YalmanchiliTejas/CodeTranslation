#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n;
  cin>>n;
  vl a(n);
  ll dp[n];
  rep(i,n){
      cin>>a[i];
      if(i==0){
          dp[0]=a[0];
      }
      dp[i]=dp[i-1]+a[i];
  }
  ll ans=0;
  rep(i,n){
      ll tmp=dp[n-1]-dp[i];
      tmp%=MOD;
      ans+=a[i]*tmp;
      ans%=MOD;
  }
  print(ans);
}
