#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
#include<cstdio>
#include<time.h>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define pd(a,n) for(int i=0;i<n;i++)cout<<a[i]<<((i==n-1)?"\n":" ")
#define pdd(a,n,m)for(int i=0;i<m;i++)pd(a,m)
#define mp make_pair
#define pb push_back
#define ll __int64
#define __int64 long long
#define P pair<int,int>
#define PP pair<P,int>

ll a,b,ab;
ll x,y;
/// abピザをk枚買うと
//aを max(0,x-k)枚、bをmax(0,y-k)枚

int main(){

  cin>>a>>b>>ab>>x>>y;
  ll ans=1000000000;
  for(ll i=0;i<=max(x,y);i++){
    ll cost=ab*2*i + max(0LL,x-i)*a + max(0LL,y-i)*b;
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
  return 0;
}
