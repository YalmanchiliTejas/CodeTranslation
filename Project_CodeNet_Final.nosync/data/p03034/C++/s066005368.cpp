#include <bits/stdc++.h>

using namespace std;

int a[100005];
bool vis[100005];

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	long long res = 0;
	
	vis[0] = 1;
	vis[n - 1] = 1;
	
	for (int i = 1; i <= n - 1; i++) {
		long long sum = 0;
		int idx = 0;
		
		vector <int> tmp;
		
		while (true) {
			idx++;
			int l = i * idx;
			int r = n - 1 - i * idx;
			
			if (l > n - 1 || r < 0) break;
			if (r <= i) break;
			
			if (l == r) break;
			if (vis[l]) break;
			if (vis[r]) break;
			vis[l] = 1;
			sum += a[l];
			vis[r] = 1;
			sum += a[r];
			
			res = max(res, sum);
			tmp.push_back(l);
			tmp.push_back(r);
		}
		
		for (int j = 0; j < tmp.size(); j++) vis[tmp[j]] = 0;
	}
	
	printf("%lld\n", res);
}
