#include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define se second
#define ll long long
#define pb push_back
#define mpr make_pair
#define Senky_Bansal ios_base::sync_with_stdio(false);
#define IIIT_ALLAHABAD    cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{   
    Senky_Bansal
    IIIT_ALLAHABAD
    ll n;
  cin>>n;
  ll ans=0;
  ll mx=0;
  for(int i=1;i<=n;i++)
  {
    ll a;
    cin>>a;
    if(a>=mx)
      ans++;
    mx=max(mx,a);
  }
  cout<<ans<<endl;
        






}