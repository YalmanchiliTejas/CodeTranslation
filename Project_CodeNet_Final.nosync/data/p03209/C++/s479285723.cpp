#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;
ll bur[100],pat[100];


ll cnt(ll n,ll x)
{
  //cout<<"nx"<<n<<" "<<x<<endl;
  ll res=0;

  if(n==0)
  {
    return 1;
  }
  if(x==0)return 0;
  if(x<=bur[n-1])
  {
    res+=cnt(n-1,x-1);
  }
  else if(x==bur[n-1]+1)
  {
    res+=pat[n-1]+1;
  }
  else
  {
    res+=pat[n-1]+1+cnt(n-1,x-bur[n-1]-2);
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,x;
  cin>>n>>x;
  bur[0]=1;
  pat[0]=1;
  rep(i,n)
  {
    bur[i+1]=bur[i]*2+3;
    pat[i+1]=pat[i]*2+1;
  }
  //rep(i,n+1)cout<<bur[i]<<" "<<pat[i]<<endl;

  
  cout<<cnt(n,x-1)<<endl;


  return 0;

}
