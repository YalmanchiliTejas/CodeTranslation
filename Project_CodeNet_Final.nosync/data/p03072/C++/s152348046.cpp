//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debug cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll n,m,c,ans,temp;
void solve()
{
   cin>>n;ll ar[n];
   for(int i=0;i<n;i++)
   {
       cin>>ar[i];
   }
   ans=1;ll chk=ar[0];
   for(int i=1;i<n;i++)
   {
       if(max(ar[0],chk)<=ar[i])
        ans++;
        chk=max(chk,ar[i]);
   }
   cout<<ans<<endl;
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}
