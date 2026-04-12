#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	long long int n, a;
	cin >> n;
	vector<long long int> arr;
	for(long long int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	long long int ans = 0;
	long long int sum = arr[n - 1];
	for(long long int i = n - 2; i >= 0; i--) {
		ans += (arr[i] * sum);
		ans %= 1000000007;
		sum += arr[i];
		sum %= 1000000007;
	}
	cout << ans;
	return 0;
}