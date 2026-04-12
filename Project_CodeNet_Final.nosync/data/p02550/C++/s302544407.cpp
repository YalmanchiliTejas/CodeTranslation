#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
const ll Mod=1000000007;
const ll INF=999999999999999999;
const ll NN=(ll)(1e6+5);
ll min(ll x,ll y){if(x<y) return x;return y;}
ll max(ll x,ll y){if(x>y) return x;return y;}
ll power(ll x,unsigned ll y) 
{ 
    if (y==0) 
        return 1; 
    else if (y%2==0) 
        return power(x,y/2)*power(x,y/2); 
    else
        return x*power(x,y/2)*power(x,y/2); 
}
ll hcf(ll a,ll b) 
{ 
    if(b==0) 
        return a; 
    return hcf(b,a%b);  
}
int main()
{
   fio;
   /*#ifndef ONLINE_JUDGE 
    	freopen("input.txt", "r", stdin); 
    	freopen("output.txt", "w", stdout); 
    	freopen("error.txt", "w", stderr); 
   #endif*/
   ll TT=1;
   //cin>>TT;
   while(TT--)
   {
       ll i,j,n,x,m;
       cin>>n>>x>>m;
       vector <ll> v;
       v.pb(x);
       ll l=x,y;
       map <ll,ll> mp;
       mp[x]++;
       while(1)
       {
           y=(l*l)%m;
           mp[y]++;
           if(mp[y]>1)
            break;
           v.pb(y);
           if(v.size()==n)
            break;
           l=y;  
       }
       ll ans=0;
       for(auto u:v)
        ans+=u;
       ll ind=-1;
       for(i=0;i<v.size();i++)
        if(v[i]==y)
         {
             ind=i;
             break;
         } 
       ll z=v.size()-ind,sum=0;
       n-=v.size();
       for(i=ind;i<v.size();i++)
        sum+=v[i];
       ans+=(n/z)*sum;
       for(i=ind;i<ind+(n%z);i++)
        ans+=v[i];
       cout<<ans;  
   }
}