#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	int x, m;
	cin >> n >> x >> m;

	vector<int> cir;	
	int cur = x;
	vector<bool> vis(m);
	int start = -1;
	long long ans = 0;
	long long sum = 0;
	while(n > 0) {
		if(cur == 0) {
			cout << ans << '\n';
			exit(0);
		}
		if(vis[cur]) {
			start = cur; 
			break;
		}
		n -= 1;
		ans += cur;
		vis[cur] = true;
		cur = 1LL * cur * cur % m;
	}

	if(n == 0) {
		cout << ans << '\n';
		exit(0);
	}

	for(int i = 0; i < m; ++i) {
		vis[i] = false;
	}
	while(!vis[start]) {
		cir.emplace_back(start);
		vis[start] = true;
		sum += start;
		start = 1LL * start * start % m;
	}

	int s = cir.size();
	ans += n / s * sum;
	for(int i = 0; i < n % s; ++i) {
		ans += cir[i];
	}

	cout << ans << '\n';

	return 0;
}