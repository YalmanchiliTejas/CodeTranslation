#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

void mkay(ll& a){
	if(a >= mod)
		a -= mod;
}


ll ps[200001];
int arr[200001];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		mkay(ps[i] = ps[i - 1] + arr[i]);
	}
	ll ans = 0;

	for(int i = 1; i <= n; i++){
		ll temp;
		temp = (arr[i] * ps[i - 1]) % mod;
		mkay(ans += temp);
	}
	cout << ans << endl;
}