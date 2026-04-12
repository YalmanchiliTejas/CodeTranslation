#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define boost	    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector <vector <ll >> dp;

ll max(ll a, ll b)  { return a > b ? a : b; }
ll min(ll a, ll b)  { return a > b ? b : a; }

ll go(int i, int j, vector <ll> &a) {
	if(i > j) return 0;

	if(i == j) return a[i];

	if(dp[i][j] != -1) return dp[i][j];

	ll x = a[i] + min(go(i + 2, j, a), go(i + 1, j - 1, a));
	ll y = a[j] + min(go(i + 1, j - 1, a), go(i, j - 2, a));
	dp[i][j] = max(x, y);
	return dp[i][j];
}

void solve() {
	boost;
	int n;
	cin >> n;
	vector <ll> a(n);
	ll sum = 0;
	dp.resize(n, vector <ll > (n, -1));
	rep(i, 0, n) { 
		cin >> a[i];
		sum += a[i];
	}
	
	//cout << go(0, n - 1, a) << endl;
	//cout << sum << endl;
	ll x = go(0, n - 1, a);
	ll y = sum - x;
	cout << x - y << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while(t--)
		solve();

	return 0;
}
