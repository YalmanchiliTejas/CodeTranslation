#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e5 + 100;

string s[maxn];

int main () {
	ios_base::sync_with_stdio (false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '.' + s[i] + '.';
	}
	for (int i = 0; i <= m + 1; i++) {
		s[n + 1] += '.';
		s[0] += '.';
	}
	
	if (s[1][1] != '#')
		return cout << "Impossible" << endl, 0;
	int xnow = 1, ynow = 1;
	while (true) {
		if (s[xnow + 1][ynow] == '#' and s[xnow][ynow + 1] == '#')
			return cout << "Impossible" << endl, 0;
		if (s[xnow - 1][ynow] == '#' and s[xnow][ynow - 1] == '#')
			return cout << "Impossible" << endl, 0;
		if (s[xnow + 1][ynow] == '#')
			xnow ++;
		else if (s[xnow][ynow + 1] == '#')
			ynow ++;
		else if (xnow == n and ynow == m)
			return cout << "Possible" << endl, 0;
		else
			return cout << "Impossible" << endl, 0;
	}
}
