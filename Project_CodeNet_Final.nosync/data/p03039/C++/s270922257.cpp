#include <bits/stdc++.h>
using namespace std;
const int maxn = 234567;
const int mod = 1000000007;
int mul(long long a, long long b){
	return a * b % mod;
}
int inv(int x){
	int r = 1, b = mod - 2;
	for(; b; b >>= 1, x = mul(x, x)) if(b&1) r = mul(r, x);
	return r;
}
int fat[maxn], ifat[maxn], sum[maxn];
void init(){
	fat[0] = 1;
	for(int i = 1; i < maxn; i++) fat[i] = mul(fat[i - 1], i);
       	ifat[maxn - 1] = inv(fat[maxn - 1]);	
	for(int i = maxn - 2; i >= 0; i--) ifat[i] = mul(ifat[i + 1], i + 1);
	for(int i = 1; i < maxn; i++){
		sum[i] = sum[i - 1] + i;
		if(sum[i] >= mod) sum[i] -= mod;
	}
}
int ncr(int n, int k){
	if(n < k) return 0;
	return mul(fat[n], mul(ifat[k], ifat[n - k]));
}
int main(){
	int n, m, ch; cin >> n >> m >> ch;
	if(n > m) swap(n, m);
	init();
	int magic = ncr(n * m - 2, ch - 2);
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = 0; k < m; k++){
				int tot = sum[k] + sum[m - k - 1];
				if(tot >= mod) tot -= mod;
				tot += mul(j - i, m);
				if(tot >= mod) tot -= mod;
				ans += mul(tot, magic);
				if(ans >= mod) ans -= mod;
			}	
		}
		for(int j = 0; j < m; j++){
			int tot = sum[m - j - 1];
			ans += mul(tot, magic);
			if(ans >= mod) ans -= mod;
		}
	}
	cout << ans << endl;
	return 0;;
}
