#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
#define irp(i,s,e) for(int i=(s);i>(e);--i)
string N;
int K;
int dp[100][4][2];// digit DP, [|N|: 0 origin][k:0~3][notLessThen?], init = 0
int lt = 0, eq = 1;//lt: <, eq: =

int solve(){
	int dn = N.size();
	int di = N[0] - '0';
	dp[0][0][lt] = 1;
	dp[0][1][lt] = di>0? di-1:di;
	dp[0][1][eq] = 1;

	rp(i,1,dn){
		di = N[i] - '0';
		int lt0 = 1, ltn = 9;//<ni
		int eq0 = di? 1:0, eqn = max(0, di-1);//=ni

		// lt <
		rp(k,0,4){
			int x = dp[i-1][k][lt] * lt0 + dp[i-1][k][eq] * eq0;
			if(k) x += dp[i-1][k-1][lt] * ltn + dp[i-1][k-1][eq] * eqn;
			dp[i][k][lt] = x;
		}

		// eq =
		irp(k,2,-1){
			if(dp[i-1][k][eq]){
				if(di) dp[i][k+1][eq] = di>0;
				else dp[i][k][eq] = 1;
			}
		}

	}

	return dp[dn-1][K][lt] + dp[dn-1][K][eq];
}

int main(){
	cin>>N>>K;
	cout<< solve() <<endl;

	// cout<<N<<" "<<K<<"\n";;///
	// cout<<"       k0   k1   k2   k3\n";///
	// rp(i,0,N.size()){
	// 	rp(j,0,2){
	// 		printf((j%2? "=n%d:":"<n%d:"),i);
	// 		rp(k,0,4){ printf("%5d",dp[i][k][j]); }
	// 		puts("");
	// 	}
	// }

}
