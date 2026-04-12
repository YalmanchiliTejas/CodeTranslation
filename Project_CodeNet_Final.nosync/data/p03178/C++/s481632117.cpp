#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

const int maxn = 1e4 + 10;
const int maxd = 1e2 + 10;
const ll mod = 1e9 + 7;

ll dp[maxn][maxd];
int d;
string s;

ll solve(int n, int rem){
	if(n == 0)
		return (rem ? 0 : 1);
	if(dp[n][rem] != -1)
		return dp[n][rem];
	ll ans = 0;
	for(int i = 0; i < 10; i++)
		ans += solve(n - 1, (rem + i) % d), ans %= mod;
	return dp[n][rem] = ans;	
}

ll calc(){
	int sum = 0, n = (int)s.size();
	
	ll ans = 0;
	
	for(int i = 0; i < n; i++){
		int top = s[i] - '0';
		for(int j = 0; j < top; j++){
			int rem = (sum + j) % d;
			ans += solve(n - i - 1, rem), ans %= mod;
		}
		sum += top;
		sum %= d;
	}
	
	ans--;
	ans += mod;
	ans %= mod;
	
	if(sum == 0)
		ans++, ans %= mod;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> d;
	memset(dp, -1, sizeof(dp));
	
	cout << calc() << endl;
	
	return 0;
}