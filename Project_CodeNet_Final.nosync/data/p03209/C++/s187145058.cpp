#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a(51,1),p(51,1);

ll f(ll n,ll x)
{
  if(x==0) return 0;
  else if(x==a[n]) return p[n];
  else if(x<=a[n-1]+1)
  {
    return f(n-1,x-1);
  }
  else if(x==a[n-1]+2)
  {
    return p[n-1]+1;
  }
  else
  {
    return p[n-1]+1+f(n-1,x-a[n-1]-2);
  }
}

int main()
{
  ll n,x;
  cin>>n>>x;
  for (int i = 1; i < 51; ++i)
  {
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  cout<<f(n,x)<<endl;
}