#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long ans;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> n >> k;
	if(k == 0) ans = n * n;
	else{
		for(int i=k+1; i<=n; ++i){
			ans += (i-k)*((n-k)/i) + (1+min(n,(n-k)/i*i+i-1)-k-(n-k)/i*i);
//			cout << i << " " << ans << "\n";
		}
	}
	cout << ans << "\n";
}