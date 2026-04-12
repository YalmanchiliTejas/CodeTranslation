#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
using P=pair<long long,long long>;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  ll n;
  cin >> n;
  vector<ll>vec(n);
  rep(i,n) cin >> vec[i];
  ll ok=INF,ng=-1;
  
  while(ok-ng>1){
    ll mid=(ok+ng)/2;
    ll cnt=0;
    rep(i,n) cnt+=(vec[i]+mid+1)/(n+1);
    if(cnt<=mid)ok=mid;
    else ng=mid;
  }
  for(ll i=max(0ll,ok-100000);i<=ok;i++){
    ll sum=0;
    rep(j,n){
      sum+=(vec[j]+i+1)/(n+1);
    }
    if(sum<=i){
      cout << i << endl;
      return 0;
    }
  }
}
