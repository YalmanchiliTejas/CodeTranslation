#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	string S;
	int D; 
	cin >> S >> D; 
	int L = S.size(); 
	int P = 1e9 + 7; 
	int dp[10010][110][2] = {}; // leading zerosを補ってL桁と見る．dp[上からi桁][mod D][未満確定？]．あとで0の分の1個を引くのを忘れるな．
	dp[0][0][0] = 1; 
	for(int i = 0; i < L; i++){
        	for(int j = 0; j < D; j++){
        		for(int k = 0; k <= 1; k++){
				for(int r = 0; r <= (k ? 9 : S.at(i) - '0') ; r++){
					dp[i+1][(j+r) % D][k || (r < S.at(i) - '0')] 
					= (dp[i+1][(j+r) % D][k || (r < S.at(i) - '0')] + dp[i][j][k]) % P; 
				}
			}
		}
	}
	int ans = 1e9 + 6; 
	for(int k = 0; k <= 1; k++){
		ans += dp[L][0][k]; 
		if(ans >= P){ans -= P;}
	}
	cout << ans << endl; 
}