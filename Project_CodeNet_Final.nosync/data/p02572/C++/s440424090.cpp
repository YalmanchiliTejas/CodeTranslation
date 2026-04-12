#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

vector <int> dx = {-1,1,0,0};
vector <int> dy = {0,0,-1,1};

int main(){

	ll n;cin>>n;
	vector<int> a(n);
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans = 0; 
	ll sum = 0;
	for(i=0;i<=n-2;i++){
		sum += a[i];
		sum %= MOD;
	}
	sum = sum%MOD;
	for(i=n-1;i>=1;i--){
		ans += (a[i]* sum)%MOD;
		ans = ans%MOD;
		sum = (sum - a[i-1] + MOD)%MOD;
	}

	
	cout<< (ans+ MOD)%MOD<<"\n";
}