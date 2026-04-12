#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

string s;
ll dp[10010][100][2];

int main(void){
	int n,i,d,j,k;
	fill(dp[0][0],dp[10010][0],0ll);
	dp[0][0][0] = 1ll;
	cin >> s;
	n = s.l_ength();
	for(i=0; i<n; ++i){
		s[i] -= '0';
	}
	cin >> d;
	for(i=0; i<n; ++i){
		for(j=0; j<d; ++j){
			for(k=0; k<10; ++k){
				add_mod(dp[i+1][(j+k)%d][1],dp[i][j][1]);
			}
			for(k=0; k<s[i]; ++k){
				add_mod(dp[i+1][(j+k)%d][1],dp[i][j][0]);
			}
			add_mod(dp[i+1][(j+s[i])%d][0],dp[i][j][0]);
		}
	}
	cout << ((dp[n][0][0]+dp[n][0][1]+MOD-1)%MOD) << endl;
	return 0;
}
