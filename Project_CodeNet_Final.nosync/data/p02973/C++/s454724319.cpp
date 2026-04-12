#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define ll long long int
#define INF INT_MAX
#define mod
#define chutiyaap ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll MinimumNumIncreasingSubsequences(ll arr[], ll n) 
{ 
    multiset<ll> last;
    for (ll i = 0; i < n; i++) {
        multiset<ll>::iterator it = last.lower_bound(arr[i]);
        if (it == last.begin()) 
            last.insert(arr[i]); 
  
        else { 
            it--; 
            last.erase(it); 
            last.insert(arr[i]);  
        } 
    } 
    return last.size();
} 
int main()
{
	chutiyaap;
	ll n;cin>>n;
	ll a[n+1];for(ll i=0;i<n;i++)cin>>a[i];
	cout<<MinimumNumIncreasingSubsequences(a,n);
}
