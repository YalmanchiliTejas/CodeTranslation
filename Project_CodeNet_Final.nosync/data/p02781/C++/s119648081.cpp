#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
using namespace std;
int dp[110][4][2][2], n;
string s;
ll fun(int a, int b, int c, int t){
	if(b < 0)
		return 0;
	if(a == n){
		if(b == 0)
			return 1;
		return 0;
	}
	if(dp[a][b][c][t] != -1)
		return dp[a][b][c][t];
	int low = 0;
	int high = (t == 1) ? (s[a] - '0') : 9;
	ll ans = 0;
	for(int i = low; i <= high; i++){
		if(i){
			ans += fun(a + 1, b - 1, c, i == (s[a] - '0') ? t : 0);
		}
		else ans += fun(a + 1, b, 1, i == (s[a] - '0') ? t : 0);
	}
	return dp[a][b][c][t] = ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	int k;
	cin >> k;
	n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << fun(0, k, 0, 1) << '\n';

}