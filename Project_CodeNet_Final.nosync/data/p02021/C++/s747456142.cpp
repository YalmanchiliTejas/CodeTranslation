#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define inf 1000000007

int main() {
	int n;
	cin >> n;
	int all = 0;
	int ma = inf;
	rep(i, n) {
		int w;
		cin >> w;
		all += w;
		ma = min(ma, all / (i + 1));
	}
	cout << ma << endl;
}
