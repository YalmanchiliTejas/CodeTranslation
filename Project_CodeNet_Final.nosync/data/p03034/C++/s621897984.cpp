#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, val[maxn];
bool used[maxn];
long long ans;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0;i < n;++i)cin >> val[i];
	--n;
	for(int c = 1;c < n;++c){
		long long sum = 0;
		for(int k = 1;(k + 1) * c < n and !used[c * k] and !used[n - c * k] and (((c * k) << 1) != n);++k){
			ans = max(sum += val[c * k] + val[n - c * k], ans);
			used[c * k] = used[n - c * k] = true;
		}
		for(int k = 1;k * c < n and (used[c * k] || used[n - c * k]);++k){
			used[c * k] = used[n - c * k] = false;
		}
	}
	cout << ans << '\n';
}