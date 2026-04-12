#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll dp[110][5][2];

int main(void){
	int n,k,i,j,d;
	string s;
	cin >> s;
	n = s.l_ength();
	cin >> k;
	dp[0][0][0] = 1ll;
	for(i=0; i<n; ++i){
		s[i] -= '0';
		for(j=0; j<4; ++j){
			if(s[i]){
				dp[i+1][j][1] += dp[i][j][0];
				for(d=1; d<s[i]; ++d){
					dp[i+1][j+1][1] += dp[i][j][0];
				}
				dp[i+1][j+1][0] += dp[i][j][0];
			}else{
				dp[i+1][j][0] += dp[i][j][0];
			}
			dp[i+1][j][1] += dp[i][j][1];
			for(d=1; d<10; ++d){
				dp[i+1][j+1][1] += dp[i][j][1];
			}
		}
	}
	cout << (dp[n][k][0]+dp[n][k][1]) << endl;
	return 0;
}
