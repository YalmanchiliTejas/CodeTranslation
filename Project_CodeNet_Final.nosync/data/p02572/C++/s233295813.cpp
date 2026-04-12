/**
*    author:  yuya1234
*    created: 29.08.2020 21:11:38
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define SORT(x) sort(x.begin(),x.end())
#define SORTD(x) sort(x.rbegin(),x.rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define SZ(x) ll(x.size())

#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  ll n;
  cin>>n;

  ll *a=new ll[n];
  ll sum=0;

  REP(i,n)
  {
    cin>>a[i];
    sum+=a[i];
  }

  ll ans=0;
  ll mod=1000000007;

  REP(i,n-1)
  {
    sum-=a[i];
    ans+=(sum%mod)*a[i];
    ans%=mod;
  }

  cout<<ans<<endl;


  return 0;
}