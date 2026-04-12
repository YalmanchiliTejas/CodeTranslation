#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define PB push_back
#define be(v) v.begin(), v.end()
#define MOD 1000000007
#define endl "\n"
void solve(){
	ll n; cin>>n;
	ll total = 0;
	std::vector<ll> v(n,0);
	std::vector<ll> pre(n,0);
	for(ll i = 0; i<n; i++){
		cin>>v[i];
		total+=v[i];
		pre[i] = total;
	}
	ll sum = 0;
	for(ll i = 0; i<n; i++){
		sum += ((v[i]%MOD)*((total-pre[i])%MOD))%MOD;
		sum%=MOD;
	}
	cout<<(sum%MOD)<<endl;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin>>t;
	while(t-->0){
		solve();
	}
	return 0;
}
