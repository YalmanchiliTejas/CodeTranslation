#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
using si = set<int>;
using sll = set<ll>;


ll dp[3005][3005];


int main(){
	int n; cin >> n;
	vi a(n + 2);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j + i - 1 <= n; j++){
			int l = j, r = j + i - 1;
			if (l == r){
				dp[l][r] = a[l];
			}
			else{
				dp[l][r] = max(a[r] - dp[l][r - 1], a[l] - dp[l + 1][r]);
			}
		}
	}
	cout << dp[1][n] << endl;
	return 0;
}
