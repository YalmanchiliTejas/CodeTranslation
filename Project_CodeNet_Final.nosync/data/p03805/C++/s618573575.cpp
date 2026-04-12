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
int test[213][213], aa[213];
signed main() {
	int n, m, a, b, ans = 0; cin >> n >> m;
	for (int h = 0; h < m; h++) {
		cin >> a >> b;
		test[a][b] = 1;
		test[b][a] = 1;
	}
	for (int h = 0; h < n; h++) {
		aa[h] = h + 1;
	}
	do{
		int c = 0;
		for (int h = 1; h < n; h++) {
			if (test[aa[h - 1]][aa[h]] == 0) { c = 1; }
		}
		if (c == 0) { ans++; }
	} while (next_permutation(aa + 1, aa + n));
	cout << ans << endl;
}