#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long ll;
int a[3001];
ll d[3001][3001];
ll mod = 998244353;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int n, s; cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	d[0][0] = 0;// i까지왔는데의 합이 S인 경우의 수
	for (int i = 1; i <= n; i++) {
		d[i][a[i]] = i;
		for (int j = 0; j <= s; j++) {
			d[i][j] += d[i - 1][j];
			if (j - a[i] >= 0)
				d[i][j] += d[i - 1][j - a[i]];
			d[i][j] %= mod;
		}
		ans += d[i][s]; ans %= mod;
	}

	cout << ans << '\n';



}


