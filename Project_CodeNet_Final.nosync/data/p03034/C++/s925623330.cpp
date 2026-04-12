#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n, ans;
vector<Int> a;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(auto &i:a) cin >> i;
	for(Int i=1; i<=n-1; ++i){
		Int tmp = 0;
		if((n-1) % i == 0){
			for(Int j=0; i*j<n-1-i*j; ++j){
				tmp += a[i*j] + a[n-1-i*j];
				ans = max(ans, tmp);
			}
		}else{
			for(Int j=0; i*j+i<n-1; ++j){
				tmp += a[i*j] + a[n-1-i*j];
				ans = max(ans, tmp);
			}
		}
	}
	cout << ans << "\n";
}