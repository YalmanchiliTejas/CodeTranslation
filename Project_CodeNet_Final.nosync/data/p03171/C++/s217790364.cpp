#include <bits/stdc++.h>

using namespace std;

#define INF (1ll << 62)
#define pb push_back
#define ii pair<int,int>
#define OK cerr <<"OK"<< endl
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define endl '\n'

int dp[3002][3002][2];
vector<int> arr;

int f(int l, int r, int player) {

	if(l > r)
		return 0;

	int &ret = dp[l][r][player];
	if(ret != -1)
		return ret;

	if(player == 1) {

		return ret = min(-arr[l] + f(l + 1, r, player ^ 1), -arr[r] + f(l, r - 1, player ^ 1)); 

	} else {
		return ret = max(arr[l] + f(l + 1, r, player ^ 1), arr[r] + f(l, r - 1, player ^ 1));
	}
}

signed main () {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  int n;

  cin >> n;

  arr.resize(n);

  for(int &x: arr)
  	cin >> x;

  cout << f(0, n-1, 0) << endl;

}