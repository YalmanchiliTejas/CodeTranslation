#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

bool ok[8][8];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	rep(i, m) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		ok[a][b] = ok[b][a] = true;
	}
	vector<int>v(n); iota(v.begin(), v.end(), 0);
	int cnt = 0;
	do {
		if (*v.begin())break;
		bool flag = true;
		rep(i, n - 1) {
			if (!ok[v[i]][v[i + 1]])flag = false;
		}
		if (flag)cnt++;
	} while (next_permutation(v.begin(), v.end()));
	printf("%d\n", cnt);
}