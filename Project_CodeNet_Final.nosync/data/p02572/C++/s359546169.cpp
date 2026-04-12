/****************************************************************************
Is this the real life? Is this just fantasy?
Caught in a landslide, no escape from reality
Open your eyes, look up to the skies and see
I'm just a poor boy, I need no sympathy
Because I'm easy come, easy go, little high, little low
Any way the wind blows doesn't really matter to me, to me!!!
--------------------------------------------------
CP is quite cool.It becomes cooler when you enjoy learning new things
******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define endl "\n"
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define pool(i,a,b) for(int i=a;i>=b;i--)
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vb vector<bool>
#define all(x) x.begin(),x.end()
#define sz(a) a.size()
#define ff first
#define ss second
#define debug(x) cout<<#x<<" = "<<x<<endl;
const int mod=1e9+7;

void solve()
{
  int n;
  cin>>n;
  vi a(n);

  rep(i,n)  
    cin>>a[i];

  vll pref(n+1,0);
  for(int i=n-1;i>=0;i--)
  {
    pref[i]+=pref[i+1]+a[i];
  }


  ll ans=0;
  for(int i=0;i<n;i++)
  {
    ll res=pref[i+1];
    res%=mod;
    res*=a[i];
    ans+=res;
    ans%=mod;

  }

  cout<<(ans+mod)%mod<<endl;


} 

int main()
{

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t=1;
  // cin>>t;
  while(t--)
  {
    solve();
  }

  return 0;
}
