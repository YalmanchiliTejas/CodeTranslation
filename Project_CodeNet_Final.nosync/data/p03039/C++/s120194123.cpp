#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 1000000007

ll mod_inv(ll n)
{
    ll left=MOD-2;  // define MOD!
    ll num=n;
    ll ans=1;
    while(left!=0)
    {
        if(left%2==1)ans=(ans*num)%MOD;
        left/=2;
        num=(num*num)%MOD;
    }
    return ans;
}

int main()
{
  ll n,m,k;cin>>n>>m>>k;
  ll total=0;
  ll i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
      ll tpat=0;
      ll a=j;
      ll b=(n-i-1);
      tpat+=a*b*(a+b+2)/2;
      a=m-j-1;
      tpat+=a*b*(a+b+2)/2;
      a=n-i-1;
      tpat+=a*(a+1)/2;
      a=m-j-1;
      tpat+=a*(a+1)/2;
      total=(total+tpat)%MOD;
    }
  }
  ll pat=1;
  for(i=1;i<=k;i++)
  {
    pat=pat*((n*m+1-i)*mod_inv(i)%MOD);
    pat%=MOD;
  }
  ll kc2=k*(k-1)/2%MOD;
  ll nmc2=(n*m)*(n*m-1)/2%MOD;
  total=(total*kc2)%MOD;
  total=(total*pat)%MOD;
  total=(total*mod_inv(nmc2))%MOD;
  cout<<total<<endl;
}
