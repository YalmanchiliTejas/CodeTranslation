#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
 
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e4 + 50;
const int D = 100 + 10;

string k;
int d;
int n;
int dp[N][D][2];

int sum2(int a, int b) {
	int c = a + b;
	if(c >= MOD) c -= MOD;
	
	return c;
}

int rek(int ind, int sum, int tight) {
	if(ind >= n) 
		return !sum;
	if(dp[ind][sum][tight] != -1) 
		return dp[ind][sum][tight];
	
	int ret = 0;
	int x = 9;
	if(tight) x = int(k[ind]) - 48;
	
	for(int i = 0; i <= x; i++) {
		ret = sum2(ret, rek(ind + 1, (sum + i) % d, (tight && i == x)));
	}
	
	dp[ind][sum][tight]=ret;
	//cout <<ind<<" "<<sum<<" "<<tight<<" "<<ret<<endl;
	return ret;
}
int main() {
	memset(dp, -1, sizeof dp);
	cin >> k >> d;
	n = k.size();
	
	cout << (rek(0, 0, 1) - 1 + MOD) % MOD;
	/*for(int i=0;i<k.size();i++) {
		for(int j=0;j<20;j++) {
			cout <<dp[i][j][1]<<" ";
		}
		cout <<endl;
	}*/
	return 0;
}