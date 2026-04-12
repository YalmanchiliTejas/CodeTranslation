#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	
	ll n;
	cin >> n;
	ll maxx,ans=0;
	for(ll i=0;i<n;i++){
		ll temp;
		cin >> temp;
		if(i==0){
			maxx = temp;
			ans++;
		} else {
			if(maxx<=temp){
				ans++;
				maxx = temp;
			}
		}
	}
	cout << ans << endl;

	return 0;
}