#include<bits/stdc++.h>
using namespace std;

#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int

const int maxr = 2e5 + 5;

int arr[maxr], prefix[maxr];
const int M = 1e9 + 7;
int32_t main()
{
	GO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = arr[i] + prefix[i - 1];
		prefix[i] %= M;
	}
	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		ans += (prefix[i] * arr[i + 1]);
		ans %= M;
	}
	cout << ans << endl;
	return 0;
}

//!