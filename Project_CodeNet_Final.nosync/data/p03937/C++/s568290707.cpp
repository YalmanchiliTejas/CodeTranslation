// Anve$hi $hukla
#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(false);cin.tie(NULL);}}$;

typedef long long LL;
const int Maxn = 200005;

int main() {
	int n, m;
	cin >> n >> m;
	vector <string> s(n);

	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}

	bool ok = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i == n - 1 && j == m - 1)
				continue;
			int cnt = 0;
			if(i != n - 1)
				cnt += (s[i + 1][j] == '#');
			if(j != m - 1)
				cnt += (s[i][j + 1] == '#');
			ok &= ((cnt < 2));
		}
	}   
	cout << (ok == 1? "Possible": "Impossible") << endl;
	return 0;
}
