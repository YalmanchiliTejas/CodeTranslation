#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define range(i,l,h) for(int i=l;i<h;i++)
#define endl '\n'
#define I INT_MAX
#define L INT_MIN
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vt vector
using namespace std;
using std::ios;
constexpr int MOD=1e9+7;
constexpr int mod=998244353;

ll fp(ll a,ll n)
{
  ll ans=1;
  while(n)
  {
    if(n&1)
    {
      ans*=a;
      ans%=MOD;
    }
    a*=a;
    a%=MOD;
    n/=2;
  }
  return ans%MOD;
}

int main()
{
  fastio;
 
  
  int n;
  cin>>n;
  vt<ll> a(n);
  vt<ll> sum(n);
  range(i,0,n)
  {
    cin>>a[i];
  }  

 sum[0]=a[0]%MOD;
 range(i,1,n)sum[i]=(sum[i-1]+a[i])%MOD;
 ll b=0;
 range(i,0,n)
 {
 // cout<<(sum[n-1]-sum[i])<<' ';
    b+=a[i]*(sum[n-1]-sum[i]+MOD);
    b%=MOD;
 }
 cout<<b;

  
}
