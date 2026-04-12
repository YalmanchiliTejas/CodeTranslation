#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define endl '\n'
using  namespace std; 
int main()
{
    fast;
   ll t=1;
   //std::cin >> t;
   while(t--)
   {
       ll n,x,m;
       std::cin >> n>>x>>m;
       ll a[m+2]={0},r,ans=0,d=x;
       ll mp[m+2]={0};
       if(n>m)
       {fr(i,1,m+2)
       {
          a[i]=a[i-1]+x%m;
          x=x%m;
          if(mp[x]==0)
          {
              mp[x]=i;
          }
          else
          {
              r=a[i]-a[mp[x]];
              ll nt=i-mp[x];
              ans=ans+((n-mp[x]+1)/nt)*r+a[((n-mp[x]+1)%nt)+mp[x]-1];
              break;
          }
          x=(x*x)%m;
       }
           cout<<ans<<"\n";
       }
       else
       {
           fr(i,1,n+1)
           {
               ans=ans+x%m;
               x=x%m;
               x=x*x;
           }
           cout<<ans<<"\n";
       }
   
   }
   
}