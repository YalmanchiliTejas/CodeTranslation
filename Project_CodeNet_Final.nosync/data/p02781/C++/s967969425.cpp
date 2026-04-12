// E - Almost Everywhere Zero
#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)
string N;
int K;
int dp[101][2][4];// digit DP, [|N|+1: 1 origin][notLessThan?][k:0~3], init = 0
int lt = 0, eq = 1;//lt: <, eq: =

int solve(){
	N = "0" + N;
	int dn = N.size();
	int di = N[0] - '0';
	dp[0][eq][0] = 1;

	rp(i,1,dn){
		di = N[i] - '0';
		int lt0 = 1, ltn = 9;//lt <
		int eq0 = di? 1:0, eqn = max(0, di-1);//eq =

		// lt <
		rp(k,0,4){
			int x = dp[i-1][lt][k] * lt0 + dp[i-1][eq][k] * eq0;
			if(k) x += dp[i-1][lt][k-1] * ltn + dp[i-1][eq][k-1] * eqn;
			dp[i][lt][k] = x;
		}

		// eq =
		irp(k,2,-1){
			if(dp[i-1][eq][k]){
				if(di) dp[i][eq][k+1] = di>0;
				else dp[i][eq][k] = 1;
			}
		}

	}

	return dp[dn-1][lt][K] + dp[dn-1][eq][K];
}

int main(){
	cin>>N>>K;
	cout<< solve() <<endl;
}