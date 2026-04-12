#include <bits/stdc++.h>

using namespace std;

const int maxd = 110;
const int maxn = 1e4+10;
const int mod = 1e9+7;

string s;
int d;
long long int dp[maxn][maxd];

long long int absm(long long int x, long long int m){
	return ((x % m) + m) % m;
}

int main(){
	cin >> s;
	cin >> d;
	s.insert(s.begin(), '0');
	long long int sum = 0;
	dp[0][0] = 1;
	for (int i = 1; i < s.length(); i++){
		for (int j = 0; j < d; j++){
			for (int k = 0; k < 10; k++){
				dp[i][j] = (dp[i][j] + dp[i-1][absm(j-k, d)]) % mod;
			}
		}
		
		for (int j = s[i]-'0' + 1; j < 10; j++){
			dp[i][(sum+j)%d] = absm(dp[i][(sum+j)%d]-1, mod);
		}
		sum += s[i]-'0';
	}

	cout << absm(dp[s.length()-1][0]-1, mod) << endl;
	return 0;
}
