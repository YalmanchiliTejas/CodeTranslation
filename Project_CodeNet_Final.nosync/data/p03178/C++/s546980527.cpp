#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back

const int P = 1e9+7;

using namespace std;

string k;
int n, d;
ll dp[2][101][10101];

/*

dp for how many different numbers o (with trailing 0s) fulfill the conditions:

dp[s][j][i]:
i -> look at the last i+1 digits of o.
j -> sum of o's digits after i mod d.
s -> are digits after position i in o the same as in k?

*/

int main(){

	cin >> k >> d;
	n = k.size();

	dp[0][0][0] = 1;
	dp[1][0][0] = 1;

	for(int i=0; i<n; i++){
		for(int j=0; j<d; j++){
			dp[1][j][i] %= P;
			dp[0][j][i] %= P;
			for(int b=0; b<10; b++){
				if(b==(k[n-i-1]-48)) dp[1][(j+b)%d][i+1] += dp[1][j][i];
				if(b<(k[n-i-1]-48)) dp[1][(j+b)%d][i+1] += dp[0][j][i];
				dp[0][(j+b)%d][i+1] += dp[0][j][i];
			}
		}
	}

	cout << (dp[1][0][n]+P-1)%P << endl;

	return 0;
}
