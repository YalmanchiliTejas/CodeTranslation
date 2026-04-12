#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int MinimumNumIncreasingSubsequences(ll arr[], ll n) 
{ 
    multiset<ll> last;
    for (ll i = 0; i < n; i++) 
	{ 
        multiset<ll>::iterator it = last.lower_bound(arr[i]); 
        if (it == last.begin()) last.insert(arr[i]); 
  
        else { 
            it--;
            last.erase(it);
            last.insert(arr[i]);
        } 
    } 
    return last.size(); // our answer is the size of last 
}
main(){
	ll n;cin>>n;
	ll a[n+1];
	for(ll i=0; i<n; i++)	cin>>a[i];
	cout<<MinimumNumIncreasingSubsequences( a, n);
	return 0;
}

