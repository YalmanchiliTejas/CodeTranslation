#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll n;
	cin>>n;
	ll arr[n],max=INT_MIN,ans=0;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		if(arr[i]>=max)
			max=arr[i],ans++;
	cout<<ans;
	return 0;
}
