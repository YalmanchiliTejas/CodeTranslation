#include <bits/stdc++.h>
using namespace std;
#define maxn 15
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
char fl[maxn][maxn];
int main() {
	int h, w;
	cin >> h >> w;
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		cin >> fl[i];
		for (int j = 0; j < w; j++)
			if (fl[i][j] == '#') cnt++;
	}
	int x = 0, y = 0;
	while (1) {
		cnt--;
		if (fl[x + 1][y] == '#') x++;
		else if (fl[x][y + 1] == '#') y++;
		else break;
	}
	if (cnt) cout << "Impossible" << endl;
	else cout << "Possible" << endl;;
	return 0;
}
