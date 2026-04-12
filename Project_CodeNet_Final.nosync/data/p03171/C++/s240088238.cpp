#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define sz size()
#define eps 0.000001
#define oo 2000000007
#define endl '\n'
#define bg begin()
#define nd end()
#define up upper_bound
#define lw lower_bound
#define debug(x) #x << " = " << x << "; "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MAX = 3000;
ll arr[MAX], dp[MAX][MAX];

ll f(int i, int j, int turn){
	if(i >= j){
		if(turn) return arr[i];
		return 0;
	} 
	ll &ans = dp[i][j];
	if(ans != -1) return ans;
	ans = 0;
	if(turn){
		ans = max(f(i + 1, j, 0) + arr[i], f(i, j - 1, 0) + arr[j]);
	}else{
		ans = min(f(i + 1, j, 1), f(i, j - 1, 1));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll tot = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		tot += arr[i];
	}
	memset(dp, -1, sizeof(dp));
	ll ans = f(0, n - 1, 1);
	cout << 2ll*ans  - tot << endl;
	
}