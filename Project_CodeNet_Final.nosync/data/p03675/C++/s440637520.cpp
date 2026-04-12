#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int n;
int a[200005];

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> n;
	FOR(i, n) cin >> a[i];
	vector<int> v;

	if (n & 1) {
		for (int i = n-1; i >= 0; i -= 2) v.push_back(a[i]);
		for (int i = 1; i < n; i += 2) v.push_back(a[i]);
	}
	else {
		for (int i = n-1; i >= 1; i -= 2) v.push_back(a[i]);
		for (int i = 0; i < n; i += 2) v.push_back(a[i]);
	}

	FOR(i, n) {
		if (i < n-1) cout << v[i] << " ";
		else cout << v[i] << endl;
	}
	return 0;
}