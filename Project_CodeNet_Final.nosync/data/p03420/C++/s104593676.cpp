#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	long long int n, k;
	cin >> n >> k;
	long long int ans = 0;
	for(int b = k+1; b <= n; b++){
		int rem = b-1;
		int count = (n - rem)/b;
		count++;
		ans += (long long int)count*(b-k);
		count--;
		int maxa = count*b + rem;
		int mod = n%b;
		if(mod >= k && mod < rem){
			ans += mod - k + 1;
		}
	}
	if(k == 0){
		ans -= n;
	}
	cout << ans << '\n';
	return 0;
}