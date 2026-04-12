#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, c) for(long long i=0; i<(long long)c; i++)
const ll INF=1000000000000001;
const ll af=1000000007;
int main() {
	string s,t;
	int n;
	ll ans=0;
	ll wa=0;
	cin >>n;
	vector<ll>a(n);
	rep(i,n){
		cin >>a[i];
		if (i>0)wa+=a[i-1];
		ans+=(a[i]%af)*(wa%af);
		ans %=1000000007;
	}
	cout <<ans<<endl;
	return 0;
}
