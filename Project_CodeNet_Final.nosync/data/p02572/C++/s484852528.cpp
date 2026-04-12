#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
ll P=1e9+7;
 void solve()
 {
     ll i,j,k,l,m,n,o,p,q,r,a[300001],prefix[300001];
    
     ll s=0;
     cin>>n;
     prefix[0]=0;
     for(i=1;i<=n;i++)
     {
         cin>>a[i];
         k=(a[i]*prefix[i-1])%P;
         s=(s+k)%P;
         prefix[i]=(prefix[i-1]+a[i])%P;
     }
     cout<<s<<endl;
 }
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     ll t=1;
    // cin>>t;
     while(t--)
     {
         solve();
     }
    return 0;
}
