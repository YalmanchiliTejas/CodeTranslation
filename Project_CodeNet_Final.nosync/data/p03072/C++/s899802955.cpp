#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	int ans = 1;
	scanf("%d", &a[0]);
	for(int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		int j = 0;
		for(j = 0; j < i; j++) {
			if(a[j] > a[i]) break;
		} if(i == j) ans++;
	} cout << ans;
	return 0;
}