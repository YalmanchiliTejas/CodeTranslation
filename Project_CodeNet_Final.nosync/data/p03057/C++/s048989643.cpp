#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

int n, m, k;
string s;
llint dp[200005], dif[200005];
llint dp2[200005][2];

llint calc()
{
	int N = (n-1)/2;
	k = min(k, N);
	
	dif[0] = 1, dif[1] = mod-1;
	llint sum = 0;
	for(int i = 0; i <= N; i++){
		sum += dif[i], sum %= mod;
		dp[i] = sum;
		dif[i+1] += dp[i], dif[i+1] %= mod;
		dif[i+k+2] += mod - dp[i], dif[i+k+2] %= mod;
	}
	
	llint ret = 0;
	for(int i = 0; i <= k; i++){
		ret += (i+1)*2 * dp[N-i] % mod;
		ret %= mod;
	}
	return ret;
}

llint calc2()
{
	llint ret = 0;
	
	dp2[1][0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				if(j == 1 && k == 1) continue;
				dp2[i+1][k] += dp2[i][j], dp2[i+1][k] %= mod;
			}
		}
	}
	ret += dp2[n][0] + dp2[n][1], ret %= mod;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			dp2[i][j] = 0;
		}
	}
	dp2[1][1] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				if(j == 1 && k == 1) continue;
				dp2[i+1][k] += dp2[i][j], dp2[i+1][k] %= mod;
			}
		}
	}
	ret += dp2[n][0], ret %= mod;
	
	return ret;
}

int main(void)
{
	cin >> n >> m;
	cin >> s;
	
	if(s[0] == 'B'){
		for(int i = 0; i < m; i++){
			if(s[i] == 'R') s[i] = 'B';
			else s[i] = 'R';
		}
	}
	
	bool diff = false;
	for(int i = 1; i < m; i++){
		if(s[i] != s[i-1]) diff = true;
	}
	if(!diff){
		cout << calc2() << endl;
		return 0;
	}
	if(n % 2){
		cout << 0 << endl;
		return 0;
	}
	
	k = n+1;
	int cnt = 0; bool flag = true;
	for(int i = 0; i < m; i++){
		if(s[i] == 'R') cnt++;
		else{
			if(cnt % 2) k = min(k, cnt);
			if(flag) k = min(k, cnt+1), flag = false;
			cnt = 0;
		}
	}
	k = (k-1)/2;
	
	cout << calc() << endl;
	
	return 0;
}