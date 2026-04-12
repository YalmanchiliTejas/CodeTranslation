#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m;
	cin >> n >> m;
	int kol = 0;
	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= m;j ++) {
			char x;
			cin >> x;
			kol += (x == '#');
		}
	}   
	if (kol != n + m - 1) cout << "Impossible";
	else cout << "Possible";
	return 0;
}