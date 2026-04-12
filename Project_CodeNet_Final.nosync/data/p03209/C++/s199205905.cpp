#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

vector<ll>a, p;
int n; ll x;

ll dfs(ll i, ll len) {
	if (i == 0) {
		if (len <= 0) {
			return 0;
		}
		return 1;
	}
	else if (len <= 1 + a[i - 1]) {
		return dfs(i - 1, len - 1);
	}
	else {
		return p[i - 1] + 1 + dfs(i - 1, len - 2 - a[i - 1]);
	}
}

int main() {
	cin >> n >> x;
	a.push_back(1);
	p.push_back(1);
	for (int i = 0; i < n; i++) {
		a.push_back(a[i] * 2 + 3);
		p.push_back(p[i] * 2 + 1);
	}
	cout << dfs(n, x) << endl;
	return 0;
}