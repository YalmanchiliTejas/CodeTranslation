#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define INF 1000000000000000

using namespace std;

ll store[3005][3005];

ll get(ll l, ll r, ll arr[])
{
    if(r<l)
        return 0;
    if(l == r)
        return arr[l];
    if(store[l][r]!=INF)
        return store[l][r];
    ll ans = -get(l,r-1,arr) + arr[r];
    ans = max(ans, -get(l+1,r,arr) + arr[l]);
    
    return store[l][r] = ans;
}

int main()
{
   FAST/**/
   
   //ll n;
   //cin>>n;
   
  ll n;
  cin>>n;
  
  for(ll i=0;i<n;i++)
    for(ll j=0;j<n;j++)
        store[i][j] = INF;
  
  ll arr[n];
  for(ll i=0;i<n;i++)
        cin>>arr[i];
   
  ll ans = get(0,n-1,arr);        
  cout<<ans;          
   
   return 0;
}