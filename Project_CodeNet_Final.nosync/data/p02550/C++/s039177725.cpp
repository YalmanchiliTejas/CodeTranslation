#include <bits/stdc++.h>
using namespace std;

long long n, x, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x >> m;
	map<long long, long long> pre;
	vector<long long> arr = {0, x};
	x = (x * x) % m;
	while(pre.find(x) == pre.end()){
		pre[x] = (int)arr.size();
		arr.push_back(x);
		x = (x * x) % m;
	}
	int cyc = pre[x], len = (int)arr.size();
	for(int i = 1; i < len; i++)
		arr[i] += arr[i - 1];
	if(n < cyc - 1) cout << arr[n] << '\n';
	else{
		long long ans = arr[cyc - 1];
		n -= cyc - 1;
		ans += (arr[len - 1] - arr[cyc - 1]) * (n / (len - cyc));
		n %= len - cyc;
		ans += arr[cyc + n - 1] - arr[cyc - 1];
		cout << ans << '\n';
	}
	return 0;
}