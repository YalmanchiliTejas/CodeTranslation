#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (1e9+7)*2;
ll a[200005];
int main(int argc, char * argv[]) 
{
	int n;
	ll sum = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans += ((sum-a[i])%mod)*a[i];
		ans %= mod;
	}
	cout<<ans/2<<endl;



    return 0;
}