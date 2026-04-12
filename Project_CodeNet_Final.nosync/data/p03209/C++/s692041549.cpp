#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
long long len[maxn], ps[maxn];
long long f(long long n, long long k){
	if(n == 0) return (k <= 0 ? 0 : 1);
	else if(k <= 1 + len[n - 1]) return f(n-1,k-1);
	return ps[n - 1] + 1 + f(n - 1, k - 2 - len[n - 1]);
}
int main() {
	len[0] = 1, ps[0] = 1;
	for(int i = 1; i < maxn; ++i){
		len[i] = 1 + len[i - 1] + 1 + len[i - 1] + 1;
		ps[i] = ps[i - 1] + 1 + ps[i - 1];
	}
	long long n, k;
	cin >> n >> k;
	cout << f(n, k);
	return 0;
}