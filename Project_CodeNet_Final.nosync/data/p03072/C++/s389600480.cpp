#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define F(i,a,b) for(i=a;a<=b;i++)
#define fi first
#define se second
#define mp make_pair
int main() {


ll n,sum=1;
cin>>n;
ll a[n],b[n];
for(ll i=0;i<n;i++)
{
  cin>>a[i];
}
ll x=a[0];
for(ll i=1;i<n;i++)
{
  if(a[i]>=x)
  {
    sum++;
    x=a[i];
  }
}
cout<<sum<<endl;

	return 0;
}
