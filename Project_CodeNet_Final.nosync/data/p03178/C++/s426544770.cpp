#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e4, M=1e9+7;
int n, d;
string k;
ll dp[mxN][100][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> d;
	n=k.size();
	for(int i=n-1; i>=0; --i) {
		for(int j=0; j<d; ++j) {
			if(i==n-1) {
				for(int l=0; l<10; ++l) {
					if(l%d==j) {
						++dp[i][j][1];
						dp[i][j][0]+=l<=k[n-1]-'0';
					}
				}
				//dp[i][j][1]=j<10;
				//dp[i][j][0]=j<=k[n-1]-'0';
				continue;
			}
			for(int l=0; l<10; ++l) {
				dp[i][j][1]=(dp[i][j][1]+dp[i+1][(j+d-l%d)%d][1])%M;
				if(l<k[i]-'0')
					dp[i][j][0]=(dp[i][j][0]+dp[i+1][(j+d-l%d)%d][1])%M;
				else if(l==k[i]-'0')
					dp[i][j][0]=(dp[i][j][0]+dp[i+1][(j+d-l%d)%d][0])%M;
			}
		}
	}
	cout << (dp[0][0][0]+M-1)%M;
}
