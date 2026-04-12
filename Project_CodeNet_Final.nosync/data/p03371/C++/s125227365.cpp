#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

 
int main(){
  int a,b,c,x,y,z=0;
  cin >> a >> b >> c >> x >> y;
  ll ans=a*x+b*y;
  int piz=max(x,y);
  while(x>0||y>0){
    if(x>0)x-=1;
    if(y>0)y-=1;
    z+=2;
    ll cur=a*x+b*y+c*z;
    ans = min(ans,cur);
  }
  cout << ans << endl;
  return 0;
}
