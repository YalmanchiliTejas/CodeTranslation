#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define mp make_pair
#define ll long long
#define pb push_back

void solve()
{

  ll n;
  cin>>n;
  vector<ll>v(n);

  ll i;
  ll sum  = 0;
  for(i=0;i<n;i++){cin>>v[i]; sum = sum + v[i];}

  ll hell = 1e9+7;


  ll ans = 0;
  for(i=0;i<n;i++)
  {
      sum = sum - v[i];
      
      ll val = sum;
      val = val%hell;

      ans = (ans + (val * v[i])%hell)%hell;
  }
  cout<<ans;


  return;
}

int main()
{

  int t = 1;
  //cin>>t;

  while(t--)
    solve();

  return 0;
}
