#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	//cin >> t;

	for(ll i=1;i<=t;i++){
		ll x;
		cin >> x;

		if(x>=30)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
 	}
}