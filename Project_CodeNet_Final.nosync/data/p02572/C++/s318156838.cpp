#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
 
const ll mod = 1E9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	vector<ll> a(N);
	int i;
	for(i = 0; i < N; i++) cin>>a[i];
	ll ans = 0, sum = 0;
	for(i = 0; i < N; i++) sum = sum + a[i];
	sum = sum % mod;
	ll sum2 = (sum * sum)%mod;
	ll sum3 = 0;
	for(i = 0; i < N; i++)
		sum3 = (sum3 + a[i]*a[i])%mod;
	ans = (((sum2 - sum3 + mod)%mod)*500000004)%mod;
	cout<<ans;
}
