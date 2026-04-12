//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
#define MAX 10011
#define mod 1000000007
#define inf 1000000000000000
#define ll long long
#define endl '\n'
string s;
int m;
ll dp[MAX][111][2];

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	cin>>m;
	reverse(s.begin(), s.end());
	for(int i = s.size(); i < MAX; i++)s += '0';
	reverse(s.begin(), s.end());

	for(int j = 0 ; j < (int)(s[0] - '0') ; j++) dp[0][j%m][0]++;
	dp[0][(s[0] - '0')%m][1]++; 	

	ll temp;	
	for(int i = 1; i < MAX ; i++){
		for(int k = 0; k < m ;k++){
			if(dp[i-1][k][0]){
				for(int j = 0 ; j < 10 ; j++){
					temp = (j+k)%m;
					dp[i][temp][0] = (dp[i][temp][0] + dp[i-1][k][0])%mod;

				}
			}
			if(dp[i-1][k][1]){
				for(int j = 0; j < (int)(s[i] -'0') ;j++){
					temp = (j + k )%m;
					dp[i][temp][0] = (dp[i][temp][0] + dp[i-1][k][1])%mod;
				}
				temp = (k + (s[i] - '0'))%m; 
				dp[i][temp][1] = (dp[i][temp][1] + dp[i-1][k][1])%mod;
			}
		}
	}
	cout<<(dp[MAX-1][0][0] + dp[MAX - 1][0][1] + mod - 1)%mod;
	return 0; 
} 