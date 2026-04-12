#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

vector<ll> a(51,1),p(51,1);

ll solver(ll n, ll x) {
  if (x==1) return (n==0)?1:0;
  else if (x<=a[n-1]+1) 
    return solver(n-1,x-1);
  else if (x==a[n-1]+2) 
    return 1+p[n-1];
  else if (x==a[n])
    return p[n];
  else return p[n-1]+1+solver(n-1,x-a[n-1]-2);
}

int main()
{
  ll n,x;
  cin>>n>>x;
  for (int i = 1; i < a.size(); ++i)
  {
    a[i]=2*a[i-1]+3;
    p[i]=2*p[i-1]+1;
  }
  cout<<solver(n,x)<<endl;
}