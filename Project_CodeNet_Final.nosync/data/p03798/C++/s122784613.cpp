#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;	
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
const int N = 1e5 + 55;
string s;
int n;
int typ[N];
bool check (int n) {
	for (int i = 0; i < n; i += 1) {
		if (typ[i] == 1 and s[i] == 'o' and typ[(i - 1 + n) % n] != typ[(i + 1) % n])
			return false;
		if (typ[i] == 1 and s[i] == 'x' and typ[(i - 1 + n) % n] == typ[(i + 1) % n])
			return false;
		if (typ[i] == 0 and s[i] == 'x' and typ[(i - 1 + n) % n] != typ[(i + 1) % n])
			return false;
		if (typ[i] == 0 and s[i] == 'o' and typ[(i - 1 + n) % n] == typ[(i + 1) % n])
			return false;
	}
	return true;
}
void solve() {
	cin >> n;
	cin >> s;
	assert((int) s.size() >= 3);
	for (int a = 0; a < 2; ++a) {
		for (int b = 0; b < 2; ++b) {
			typ[0] = a;
			typ[1] = b;
			for (int i = 2; i < n; ++i) {
				if (s[i - 1] == 'o' and typ[i - 1] == 1)
					typ[i] = typ[i - 2];
				if (s[i - 1] == 'x' and typ[i - 1] == 1)
					typ[i] = typ[i - 2] ^ 1;
				if (s[i - 1] == 'o' and typ[i - 1] == 0)
					typ[i] = typ[i - 2] ^ 1;
				if (s[i - 1] == 'x' and typ[i - 1] == 0)
					typ[i] = typ[i - 2];	 
			}
			if (check(n)) {
				for (int i = 0; i < n; i += 1) {
					if (typ[i] == 1)
						cout << 'S';
					else
						cout << 'W';
				}
				return;
			}
		}
	}
	cout << -1;
}     	