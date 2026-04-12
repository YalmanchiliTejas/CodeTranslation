#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
using namespace std;

int main()
{ 
  fast;
  ll n,x;
  cin>>n;

vector<ll> v;

for(ll i=0;i<n;i++)
{
  cin>>x;
  auto it=upper_bound(v.begin(),v.end(),-x);

  if(it==v.end())
    v.pb(-x);
  else *it=-x;
}
cout<<v.size()<<endl;
  }