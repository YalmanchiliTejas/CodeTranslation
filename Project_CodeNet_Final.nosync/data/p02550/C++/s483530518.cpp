#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 998244353
#define pii pair<ll,ll>
#define inf 1000000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

bool eq(pair<ll,ll> a)
{
    return a.ff == a.ss;
}

int main()
{
  FAST/**/
   
   ll n,x,m;
   cin>>n>>x>>m;
   
   map<ll,ll> enc;
   vector<ll> v;
   ll id = -1;
   v.pb(x);
   enc[x] = 0;
   while(v.size()<n)
   {
       ll curr = (v.back()*v.back())%m;
       auto it = enc.find(curr);
       if(it == enc.end())
       {
           enc[curr] = v.size();
           v.pb(curr);
       }
       
       else
       {
           id = it->ss;
           break;
       }
   }
   
   if(v.size() == n)
   {
       ll tot = 0;
       autoit(v,it)
            tot+=(*it);
       cout<<tot<<'\n';
       return 0;
   }
   
   ll las = (ll)v.size()-1;
   ll repe = las-id+1;
   ll sum1 = 0;
   for(ll i=id;i<(ll)v.size();i++)
        sum1+=v[i];
   ll prev = 0;
   for(ll i=0;i<id;i++)
       prev+=v[i];
   ll comp = (n-id)/repe;
   ll rem = n-(comp*repe)-id;
   prev+=(sum1*comp);
   for(ll j=0;j<rem;j++)
   {
       ll i1 = j+id;
       prev+=v[i1];
   }
   
   cout<<prev;
   
   
           
   
   return 0;        
}  

  
          
   