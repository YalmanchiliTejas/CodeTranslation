#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
//		freopen("input.txt","r",stdin);
	#endif
	ll n,k;
	cin>>n>>k;
	if(!k){
		cout << n*n << endl;
		return 0;
	}
	ll ans = 0;
	for(ll i=k+1;i<=n;i++){
		ll fr=k,to=i-1;
		while(fr <= n){
			to = min(to, n);
			ans += to - fr + 1;
			fr+=i;to+=i;
		}
		// cout << i << ' ' << ans << endl;
	}
	cout << ans << endl;
}