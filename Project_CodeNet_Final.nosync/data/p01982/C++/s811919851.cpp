#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	ll n, l, r;
	while(cin>>n>>l>>r, n>0){
		vector<ll> a(n);
		ll ans = 0;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=l; i<=r; i++){
			ll mini=-1;
			for(int j=0; j<n; j++){
				if (i%a[j]==0){
					mini = j+1;
					break;
				}
			}
			if (mini == -1){
				if (n%2==0){
					ans++;
				}
			}else{
				if (mini%2==1){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}

