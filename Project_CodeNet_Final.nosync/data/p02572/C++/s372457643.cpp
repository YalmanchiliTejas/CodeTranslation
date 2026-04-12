//invincible M15
//IIT-(ISM)Dhanbad
#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define pi  3.141592653589793238462643383279
#define ff first
#define ss second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=(int)x; i<y; i++)
#define high_functioning_sociopath  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const unsigned int M = 1000000007;
/*------------------------------------- THE GAME IS ON ---------------------------------------------*/
void solve()
{
     ll n;
     cin>>n;
     vector<ll>v(n),pref(n);
     for(int i=0;i<n;i++)cin>>v[i];
     pref[0]=v[0];
     for(int i=1;i<n;i++)
     {
            pref[i]=pref[i-1]+v[i];
     }
     ll ans=0;
     for(int i=0;i<n;i++)
     {
           ll z=(pref[n-1]-pref[i])%M;
           ans+=v[i]*z;
           ans%=M;
     }
     cout<<ans<<endl;
       
}
int32_t main()
{
   high_functioning_sociopath
   ll t=1;
   //cin>>t;
   while(t--)
   {
      solve();
   }
}