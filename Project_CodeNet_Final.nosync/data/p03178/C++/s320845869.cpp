
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;



void chmax(ll &a,ll b) {
	if (a < b)a = b;
}


string K;
ll dp[10101][101][2];
int D;

int main() {
	cin >> K;
	cin >> D;
	int n = K.size();

	dp[0][0][0] = 1;

	//配るDP
	rep(dgt, 0, n)rep(d, 0, D)rep(isless, 0, 2) {
		int c = K[dgt] - '0';
		rep(nxt, 0, 10) {
			if (isless)dp[dgt+1][(d+nxt)%D][1] += dp[dgt][d][1]%MOD;
			else {
				if (nxt < c)dp[dgt + 1][(d + nxt) % D][1] += dp[dgt][d][0]%MOD;
				else if (nxt == c)dp[dgt + 1][(d + nxt) % D][0] += dp[dgt][d][0]%MOD;
			}
		}
	}

	cout << (dp[n][0][0] + dp[n][0][1] - 1)%MOD << endl;


	
	return 0;
}