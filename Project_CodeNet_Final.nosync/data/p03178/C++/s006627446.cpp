#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int amari(int x, int y){
	int a = x % y;
	if(a < 0){
		a += y;
	}
	return a;
}

int main(){
	string S;
	int D;
	cin >> S >> D;
	int data[S.size()];
	data[0] = (S[0]-'0') % D;
	for(int i=1; i<S.size(); i++){
		data[i] = (data[i-1] + (S[i] - '0')) % D;
	}
	int dp[S.size()][D];
	for(int i=0; i<S.size(); i++){
		for(int j=0; j<D; j++){
			dp[i][j] = 0;
		}
	}
	for(int i=0; i<S[0]-'0'; i++){
		dp[0][i%D]++;
	}
	for(int i=1; i<S.size(); i++){
		for(int j=0; j<D; j++){
			for(int k=0; k<10; k++){
				dp[i][j] = (dp[i][j] + dp[i-1][amari(j-k, D)]) % mod;
			}
		}
		for(int k=0; k<S[i]-'0'; k++){
			dp[i][(data[i-1]+k)%D] = (dp[i][(data[i-1]+k)%D] + 1) % mod;
		}
	}
	if(data[S.size() - 1] == 0){
		cout << dp[S.size() - 1][0] << endl;
	}else{
		cout << amari(dp[S.size() - 1][0]-1, mod) << endl;
	}
	return 0;
}