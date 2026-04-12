
//Inbornhandsome
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long


const int N = 3005;
int cache[N][N][2];
int a[N], n;


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(auto &it : a) cin >> it;

	for(int i = 0; i < n; i ++) {
		cache[i][i][0] = a[i];
		cache[i][i][1] = -a[i];
	}

	for(int len = 2; len <= n; len ++) {
		for(int i = 0; i + len <= n; i ++) {
			int j = i + len - 1;
			cache[i][j][0] = max(cache[i+1][j][1] + a[i], cache[i][j-1][1] + a[j]);
			cache[i][j][1] = min(cache[i+1][j][0] - a[i], cache[i][j-1][0] - a[j]);
		}
	}

	cout << cache[0][n-1][0] << endl;

	return 0;
}