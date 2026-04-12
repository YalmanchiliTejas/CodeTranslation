#include <bits/stdc++.h>
using namespace std;

const int r = 1e9 + 7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;cin >> n;
	long long int sum = 0, ans = 0;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i]; sum += a[i];
		sum %= r;
	}
	for (int i = 0; i < n; ++i){
		sum -= a[i];
		sum = (sum + r)% r;
		ans += sum*a[i];
		ans%=r;
	}
	cout << ans << "\n";
	return 0;
}
