/*
 *Author - Abhas Jain
 */

#include <bits/stdc++.h>

#define F first
#define S second
#define all(c) c.begin(), c.end()
#define endl '\n'
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

const ld PI = 3.141592653589793;
const ll INF = 9223372036854775807ll;
const ll mod = 1e9 + 7;
const ll N = 3001;

ll dp[N][N];
vector<ll> a(N);
int n;

ll calc(int l, int r) {
	if (dp[l][r] != INF) {
		return dp[l][r];
	}
	if ((n - r + l) % 2) {
		return dp[l][r] = max(a[l] + calc(l + 1, r), a[r] + calc(l, r - 1));
	} else {
		return dp[l][r] = min(calc(l + 1, r) - a[l], calc(l, r - 1) - a[r]);
	}
}

void solve() 
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		dp[i][j] = INF;
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (n % 2) dp[i][i] = a[i];
    	else dp[i][i] = -a[i];
    }
    cout << calc(0, n - 1) << endl;
}

int main( )
{   
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    solve();
    return 0;
}