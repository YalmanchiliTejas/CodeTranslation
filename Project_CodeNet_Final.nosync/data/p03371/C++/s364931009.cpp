#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <time.h>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define reps(x,c) for(auto x:c)
#define all(x) begin(x), end(x)
#define pb(a) emplace_back(a) 
#define mp(a,b) make_pair((a),(b))
#define pl pair<ll,ll>
#define INF 2147483600
#define MOD 1000000007
#define fi first
#define se second
#define dbg(x) cout << #x"="<< (x) << endl
#define dbgv(x) cout<<#x<<endl;reps(y,x){cout<<y<<" ";}cout<<endl

int main(){
  ll a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  ll ans=0,ans2=INF;
  ll minn=min(x,y);
  ll maxn=max(x,y);
  if(a+b>2*c){
  	ans+=minn*2*c;
  	x-=minn;
  	y-=minn;
  	ans2=maxn*2*c;
  }
  ans+=x*a;
  ans+=y*b;
  cout<<min(ans,ans2)<<endl;
  return 0;
}