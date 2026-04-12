#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	vector<int64_t>a(n); for(auto&&i:a)cin>>i;
	int64_t base=0;
	for(auto&&i:a)base=(base+i)%mod;
	int64_t ans=0;
	for(auto&&i:a){
		base=(mod+base-i)%mod;
		ans+=base*i%mod;
		ans%=mod;
	}
	cout<<ans<<"\n"s;
}
