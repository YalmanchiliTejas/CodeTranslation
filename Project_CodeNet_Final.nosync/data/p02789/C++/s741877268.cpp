#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
using namespace std;
int get() { int r; cin >> r; return r; }
int n, m, key, p;
int t[60][60], nm[30][60];
vector<int>v[60];
bool b[60];
bool f(int nd) {
	if (nd == key)return 1;
	b[nd] = 1;
	for (int i : v[nd]) {
		if (!b[i]) {
			if (f(i)) {
				nm[p][t[nd][i]] = 1;
				return 1;
			}
		}
	}
	b[nd] = 0;
	return 0;
}

signed main() {
	if (get() == get())cout << "Yes\n"; else cout << "No\n";
}