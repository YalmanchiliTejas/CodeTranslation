#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 1e9+7;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<ll> a;
	ll sum = 0;
	for(int i=0;i<n;++i){
		int val;
		cin>>val;
		sum += val;
		a.push_back(val);
	}
	ll ans = 0;
	for(int i=0;i<n;++i){
		sum -= a[i];
		ans += (((a[i]%INF) * (sum%INF))%INF);
		ans %= INF;
	}
	cout<<ans<<'\n';

}