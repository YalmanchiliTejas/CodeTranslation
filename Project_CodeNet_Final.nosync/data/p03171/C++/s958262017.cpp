#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;

ll dp[3005][3005][2];
int a[3005];

ll f(int i, int j, int t){
	if(i > j) return 0;
	if(dp[i][j][t] != -1) return dp[i][j][t];
	if(t == 0){ 
		return dp[i][j][t] = max(f(i + 1, j, !t) + a[i], f(i, j - 1, !t) + a[j]);
	}
	else return dp[i][j][t] = min(f(i + 1, j, !t) - a[i], f(i, j - 1, !t) - a[j]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << f(0, n - 1, 0);
}