#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int a[345678], ans[345678];
signed main() {
	int n, m, cnt = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a[h];
	}
	for (int h = 0; h < n; h++) {
		if (h == 0) { ans[cnt] = a[h]; cnt++; }
		else {
			if (ans[cnt - 1] >= a[h]) { ans[cnt] = a[h]; cnt++; }
			else {
				for (int i = 0; i < cnt; i++) {
					if (ans[i] < a[h]) { ans[i] = a[h]; break; }
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}