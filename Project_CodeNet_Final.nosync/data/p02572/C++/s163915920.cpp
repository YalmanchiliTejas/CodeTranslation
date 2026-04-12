#include <bits/stdc++.h>
#define endl '\n'
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back
#define ll long long
#define rep(i,n) for (i = 0; i < n; ++i) 
#define REP(i,k,n) for (i = k; i <= n; ++i) 
#define REPR(i,k,n) for (i = k; i >= n; --i)
using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);
bool prime(ll x)
{
  if(x==1)
    return false;
  if(x==2||x==3||x==5)
    return true;
  for(ll i=2;i<=sqrt(x);i++)
  {
    if(x%i==0)
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   //freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
#endif 
   
 ll T = 1 ;
 //cin>>T;

 for(ll t=0;t<T;t++)
 {
  ll n , ans = 0 , mod = 1000000007;
  cin>>n;
  ll sum = 0;
  vector <ll> arr(n);
  for(ll i=0;i<n;i++)
    {
      cin>>arr[i];
      sum  = (sum + arr[i])%mod;
    }
  
  for(ll i = n-1;i>0;i--)
  {
    sum = (mod + sum - arr[i])%mod;
   ans = (ans + (sum*arr[i])%mod)%mod;
  }
  cout<<ans<<endl;

 }
  return 0;
}
