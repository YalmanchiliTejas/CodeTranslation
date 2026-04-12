#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[200010], r[200010];
int ans[200010];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i]; 
		r[i] = i;
	}
	
	sort(r, r + n, cmp);
	for (int i = 0; i < n; i ++) {
		int pos = i < n/2 ? n/2 : n/2-1;
		ans[r[i]] = a[r[pos]];
	}
	
	for (int i = 0; i < n; i ++) cout << ans[i] << endl;
	
	return 0;
} 