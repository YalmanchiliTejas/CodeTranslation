#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define int long long
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> ppi;
typedef vector<vector<int>> mat;
const ll cfmod = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f;
const int MAXN = 1e5+5;

string s;
int k;

int dp[MAXN][105][5];

int solve(int i, int mod, bool flag) {

	int &ans = dp[i][mod][flag];
	// debug3(i, mod ,flag);
	if(i == s.size())
		return ans = !mod;
	if(ans != -1)
		return ans;

	int limit = flag ? 9 : s[i];
	
	int aux = 0;
	for(int x = 0; x <= limit; x++) {
		aux = (aux + solve(i+1, (mod + x)%k, flag | (x < s[i])))%cfmod;
	//	if(i == 1 && mod == 0) debug2(x, aux);
	}
	
	return ans = aux;
	
}

int32_t main() {

	memset(dp, -1, sizeof dp);
	cin >> s >> k;
	for(char &i : s)
		i -= '0';

	solve(0, 0, 0);
	int ans = dp[0][0][0] - 1;
	cout << (ans < 0 ? ans + cfmod : ans) << endl;
}