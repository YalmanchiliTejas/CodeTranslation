#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const ll mod = 1e9 + 7;

string x;
int d;

ll dp[110][10100][2];

int main() {
	cin>>x;
	cin>>d;

	dp[0][0][0] = 1LL;
	for(int i=0;i<x.length();i++) {
		for(int j=0;j<d;j++) {
			int ni = i + 1;

			//cout<<"With "<<i<<" digits with "<<j<<" -> "<<dp[j][i][0]<<" and "<<dp[j][i][1]<<"\n";

			for(int nd=0;nd<=9;nd++) {
				int ndiv = (j+nd)%d;
				if(nd < int(x[i]-'0')) {
					// place each possible digit, convert 0s into 1s
					dp[ndiv][ni][1] += (dp[j][i][0] + dp[j][i][1])%mod;
					dp[ndiv][ni][1] %= mod;
				}
				else if(nd == int(x[i]-'0')) {
					// special case for 0s
					dp[ndiv][ni][0] += dp[j][i][0];
					dp[ndiv][ni][0] %= mod;

					dp[ndiv][ni][1] += dp[j][i][1];
					dp[ndiv][ni][1] %= mod;
				}
				else {
					// normal case for 1s, no place for 0s
					dp[ndiv][ni][1] += dp[j][i][1];
					dp[ndiv][ni][1] %= mod;
				}
			}
		}
	}

	cout<<(dp[0][x.length()][0]+dp[0][x.length()][1]+mod-1)%mod<<"\n";
}