#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=1e18;
const ll MOD=1e9+7;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans=INF;
  for(int i=0;i<=200000;i++){
    ll res=0;
    res+=i*c;
    res+=max(0,(x-i/2))*a+max((y-i/2),0)*b;
    chmin(ans,res);
  }
  cout << ans << endl;
    
}
