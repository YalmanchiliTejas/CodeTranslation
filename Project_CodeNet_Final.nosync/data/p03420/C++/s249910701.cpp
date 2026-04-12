#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<unordered_map>
#include<set>
#include<limits.h>
#include<string.h>
#include<functional>
#include<map>
#include<unordered_set>
#define int long long
using namespace std;

signed main() {
	int ans = 0;
	int n, k; cin >> n >> k;
	for (int i = k + 1; i <= n; i++) {
		ans += n / i*(i - k);
		int j = n%i;
		if(j)ans += max(0ll, j - (max(1ll,k))+1);
	}
	cout << ans << endl;
}