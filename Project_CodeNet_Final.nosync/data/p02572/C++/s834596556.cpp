#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define yesno(f) yes(f);no(f);
#define yes(f) if(f)cout<<"YES\n";
#define no(f) if(!f)cout<<"NO\n";
using  namespace std;
vi adj[200005];
ll mark[200005]={0},y;
void dfs(ll x)
{
    mark[x]=1;
    y++;
    fr(i,0,adj[x].size())
    {
        if(mark[adj[x][i]]==0)
        {
            dfs(adj[x][i]);
        }
    }
}
int main()
{
    fast;
   ll p=1;
   //std::cin >> t;
   while(p--)
   {
       ll n;
       std::cin >> n;
       ll presum[n]={0},a[n];
       fr(i,0,n)
       std::cin >> a[i];
       rf(i,n-1,0)
       {
           if(i==n-1)
           presum[i]=a[i];
           else
           presum[i]=(presum[i+1]+a[i])%mod;
       }
       ll sum=0;
       fr(i,0,n-1)
       {
           sum=(sum+(presum[i+1]*a[i])%mod)%mod;
       }
       cout<<sum<<"\n";
   }
}
