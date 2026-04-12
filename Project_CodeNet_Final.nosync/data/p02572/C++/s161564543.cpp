#include<bits/stdc++.h>
using namespace std;
#define ll   long long int
#define T int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define PI 3.141592653589793238462643383

int main(){
   
    fast;
    
    ll n;
    ll mod = 1000000007;
	cin >> n;
	ll arr[n];
    ll sum = 0;
	for(int i=0;i<n;i++){
	    cin >> arr[i];
        sum = (sum + arr[i]);
	}
	ll ans = 0;
	
	for(int i=0;i<n;i++){
		
	}
	for(int i=0;i<n;i++){
		sum = sum - arr[i];
		ans = (ans + ((sum%mod)*(arr[i]%mod))%mod)%mod;
	}
	cout << ans << endl;










}