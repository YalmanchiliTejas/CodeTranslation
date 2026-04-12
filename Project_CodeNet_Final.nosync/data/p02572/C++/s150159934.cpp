#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define all(x) x.begin(),x.end()
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932384626
#define mod 1000000007
#define modd 998244353

void io() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int powm(int x, int n) {
	ll res=1;
	while(n) {
		if(n%2) (res*=x)%=mod;
		x=(1LL*x*x)%mod;
		n/=2;
	}
	return res;
}

int main() {
	io();
	
	int n;
	cin>>n;
	ll sum = 0, sq = 0;
	for(int i=0;i<n;i++) {
		ll a; cin>>a;
		(sum+=a)%=mod;
		(sq+=a*a)%=mod;
	}
	(sum*=sum)%=mod;
	ll ans = (sum-sq+mod)%mod;
	ans = (ans*powm(2,mod-2))%mod;
	cout<<ans;
	return 0;
}
