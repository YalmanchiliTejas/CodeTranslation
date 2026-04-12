#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll arr[60];
ll n; 
bool isInvalid(ll k){
	ll sum_required_k = 0;
	for (ll i = 0; i < n; ++i)
	{
		sum_required_k += ceil((arr[i] - n + 1 + (ld)k)/((ld)n + 1));
	}
	// cout<<k<<" "<<sum_required_k<<endl;
	return sum_required_k > k;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	ll t;
	for (ll i = 0; i < n; ++i)
	{
		cin>>t;
		arr[i] = t;
	}
	ll min_k = 0;
	ll low = min_k, high = 1e18;
	while(high - low > 1){
		// cout<<low<<" "<<high<<".."<<endl;
		ll mid = (low + high)/2;
		if(isInvalid(mid)){
			// cout<<"right\n";
			low = mid;
		}
		else{
			// cout<<"left\n";
			high = mid;
		}
	}
	ll mini = high;
	for (ll i = max(low - 10000, (ll)0); i <= high; ++i)
	{
		// cout<<i<<" "<<isInvalid(i)<<endl;
		if(isInvalid(i) == false){
			mini = i;
			break;
		}
	}
	cout<<mini<<endl;
	return 0;
}