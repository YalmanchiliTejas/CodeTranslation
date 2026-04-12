#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
int seen[maxn];
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	long long ans = 0;
	int runs = 1;
	for(int d = 1; d < n - 1; d++){
		long long sum = 0;
		int l = d, r = n - 1 - d;
		while(r > d){
			sum += a[l] + a[r];
			ans = max(ans, sum);
			l += d;
			r -= d;
			if(r <= l && r%d == 0) break;
		}
	}
	cout << ans << endl;
	return 0;
}
