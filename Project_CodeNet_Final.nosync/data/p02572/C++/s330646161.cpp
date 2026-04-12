// In the nAme Of Allah
#include<bits/stdc++.h>
#define pb push_back
#define ins insert
#define f first
#define pp pop_back
#define ll long long int
#define fst  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const ll mod=1e9+7;
using namespace std;
ll n,a[200005],s=0,p=0;
int main()
{
   fst;
   cin>>n;
   for(ll i=0;i<n;i++)
   {
       cin>>a[i];
       p+=(a[i]%mod)*(a[i]%mod)%mod;
       s+=(a[i]%mod);
       s%=mod;
       p%=mod;
       }
       if(((s*s)-p)%2==0)
       {
           cout<<(((s*s)-p)/2)%mod;
       }
       else{
        cout<<(((s*s)-p+mod)/2)%mod;
       }
   return 0;
}
