#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
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

pair<ll,ll> get(pair<ll,ll> p)
{
    if(p.ff>p.ss)
        return mp(p.ss,p.ff);
    return p;    
}

int main()
{
  FAST/**/
   
   ll n;
   cin>>n;
   
   ll arr[3*n];
   rep(3*n)
        cin>>arr[i], arr[i]--;
   
   if(n == 1)
   {
       ll fr = 0;
       if(arr[0] == arr[1] && arr[1] == arr[2])
            fr = 1;
       cout<<fr;
       return 0;
   }
   
   ll dp[n][n];
   rep(n)
        repi(j,n)
            dp[i][j] = -inf;
   
   ll maxi[n];
   rep(n)
        maxi[i] = -inf;
        
   pair<ll,ll> p = get(mp(arr[0],arr[1]));
   ll lat = 0;
   ll las[n][n];
   rep(n)
        repi(j,n)
            las[i][j] = 0;
   maxi[p.ff] = 0;
   maxi[p.ss] = 0;
   dp[p.ff][p.ss] = 0;
   
   for(ll i=2;i<3*n;i+=3)
   {
       vector<ll> ele;
       for(ll j=0;j<3;j++)
            if(i+j<3*n)
                ele.pb(arr[i+j]);
       if(ele.size()<3)
            break;
       vector<pair<pair<ll,ll>,ll>> change;
       ll siz = change.size();
       //take one
       for(ll id=0;id<3;id++){
           ll e1 = ele[id];
           ll e2 = ele[(id+1)%3];
           ll e3 = ele[(id+2)%3];
       for(ll j=0;j<n;j++)
       {
           ll q1 = maxi[j];
           if(e2 == e3)
                q1 = max(q1, dp[min(j,e2)][max(j,e2)] + lat - las[min(j,e2)][max(j,e2)] + 1);
           change.pb(mp(mp(j,e1),q1));
       }
       }
       
       //take 2
       for(ll j=0;j<n;j++)
       {
           for(ll c1=0;c1<3;c1++)
                for(ll c2=c1+1;c2<3;c2++)
                {
                    ll c3 = (3-c1-c2);
                    ll q1 = maxi[j];
                    if(ele[c3] == j)
                        q1 = max(q1, dp[j][j] + lat - las[j][j]+1);
                    change.pb(mp(mp(ele[c1], ele[c2]), q1));
                }
       }
       
       ll add = 0;
       
       if(ele[0] == ele[1] && ele[1] == ele[2])
            lat++, add = 1;
       repi(j,n)
            maxi[j]+=add;
       
       autoit(change,it)
       {
           ll fs = it->ff.ff;
           ll sc = it->ff.ss;
           ll val = it->ss;
           if(fs>sc)
                swap(fs,sc);
           dp[fs][sc] = max(dp[fs][sc] + lat-las[fs][sc], val);
           las[fs][sc] = lat;
           maxi[fs] = max(maxi[fs], val);
           maxi[sc] = max(maxi[sc], val);
       }
               
       
       //take 0
       
       
   }
   
   ll ans = 0;
   
   for(ll i=0;i<n;i++)
        for(ll j=i;j<n;j++)
        {
            dp[i][j]+=(lat-las[i][j]);
            if(i == j && i == arr[3*n-1])
                ans = max(dp[i][j]+1,ans);
            else ans= max(dp[i][j],ans);    
        }
   
   cout<<ans;        
               
   
   return 0;        
}  

  
          
   