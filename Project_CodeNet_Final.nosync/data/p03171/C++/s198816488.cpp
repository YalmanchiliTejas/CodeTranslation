#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

const int N = 3000;
ll dp[N][N];

void solve() {

	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	// dp[i][j] = max(score of frts person - score of second person) for interval (i,j);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j] = a[i];
			} else {
				dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
			}
		}
	}

	cout << dp[0][n-1] << endl;

}

int32_t main()
{
	IOS
	// int T; cin >> T; while (T--)
	solve();
	return 0;
}
