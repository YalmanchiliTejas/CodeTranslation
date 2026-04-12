#include <bits/stdc++.h>
using namespace std;
//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> mi;
typedef vector<vector<pair<int, int>>> w_graph;
typedef vector<vector<int>> uw_graph;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	#ifdef DEBUG
		freopen("out.txt", "w", stdout);
	#endif
	const int maxn = 3005;
	ll dp[maxn][maxn];
	
	int n;
	cin >> n;
	vector<ll> a(n);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < maxn; i++){
		for (int j = 0; j < maxn; j++){
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i; j++){
			int left = j, right = j + i;
			if (right == left) dp[left][right] = a[left];
			else{
				dp[left][right] = max(a[left] - dp[left + 1][right], a[right] - dp[left][right - 1]);
			}
		}
	}
	cout << dp[0][n - 1] << endl;


	return 0;
}
