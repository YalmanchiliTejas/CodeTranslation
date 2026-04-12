#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main(){
	long long n,sum=0,ans=0;
	cin >> n;
	long long a[n+1];
	for(int i = 1 ; i <= n ; i += 1){
		cin >> a[i];
		sum += a[i];
	}
	for(int i = 1 ; i <= n ; i += 1){
		sum -= a[i];
		sum %= mod;
		ans += a[i]*sum;
		ans %= mod;
	}
	if(ans < 0){
		ans += mod;
	}
	cout << ans << endl;
}