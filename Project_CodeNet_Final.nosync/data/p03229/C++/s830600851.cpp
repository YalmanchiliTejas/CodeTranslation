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

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  sort(all(a));
  if(n==3){cout<<max(2*a[2]-a[0]-a[1],a[2]+a[1]-2*a[0])<<endl;return 0;}
  if(n==2){cout<<a[1]-a[0]<<endl;return 0;}
  rep(i,n-1)a[i+1]+=a[i];
  ll res=0;
  if(n&1)
  {

    ll l=a[n/2-1],h=a[n-1]-l;
    res=(h-l)*2-(a[n/2+1]-a[n/2-1]);
    l=a[n/2],h=a[n-1]-l;
    chmax(res,(h-l)*2+a[n/2]-a[n/2-2]);
  }
  else
  {
    ll l=a[n/2-1],h=a[n-1]-l;
    res=(h-l)*2+a[n/2-1]-a[n/2-2]-(a[n/2]-a[n/2-1]);
  }
  cout<<res<<endl;
  return 0;

}
