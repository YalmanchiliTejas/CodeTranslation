#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=53;
ll n,x,ans,f[53],g[53];
void solve(ll x,int n)
{
  // cout<<ans<<" "<<x<<" "<<n<<endl;
  // cout<<ans<<" "<<f[n]<<" "<<g[n]<<endl;
  if(x<=0 || n<0) return;
  // if(n==0) if(x>=g[n]) ans+=f[n],x-=g[n];
  if(n==0)
  {
    if(x==1) ans+=1;
    else if(x==2) ans+=2;
    else ans+=3;
  }
  else
  {
    if(x>=g[n]+1) ans+=f[n]+1,x-=g[n]+1;
    // cout<<
  }
  solve(x-1,n-1);
}
int main()
{
  cin>>n>>x;
  f[0]=g[0]=1ll;
  for(int i=1;i<N;i++) f[i]=1+2*f[i-1],g[i]=2*g[i-1]+3;
  solve(x-1,n-1);
  cout<<ans<<endl;
  return 0;
}
