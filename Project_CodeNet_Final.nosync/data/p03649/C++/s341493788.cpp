#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#define int long long
using namespace std;

int a[50];
signed main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	while (1) {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > a[k]) {
				k = i;
			}
		}
		if (a[k] < n)break;
		int S = (a[k] - (n - 1)) / n;
		if ((a[k] - (n - 1)) % n)S++;
		ans += S;
		for (int i = 0; i < n; i++) {
			if (i == k) {
				a[i] -= S*n;
			}
			else {
				a[i] += S;
			}
		}
	}
	cout << ans << endl;
}