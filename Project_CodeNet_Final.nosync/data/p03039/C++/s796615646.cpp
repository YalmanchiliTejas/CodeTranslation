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
  for(i=1;i<m;i++)
  {
    total+=n*n*(m-i)*i;
    total%=MOD;
  }
  for(i=1;i<n;i++)
  {
    total+=m*m*(n-i)*i;
    total%=MOD;
  }
  ll pat=1;
  for(i=1;i<=k-2;i++)
  {
    pat=pat*((n*m-1-i)*mod_inv(i)%MOD)%MOD;
  }
  cout<<total*pat%MOD<<endl;
}
