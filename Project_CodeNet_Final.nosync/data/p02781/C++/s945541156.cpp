//abc154_e.cpp
//Sat Mar 28 18:09:59 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	string n;
	cin >> n;
	int k;
	cin >> k;

	ll dp[105][2][4];
	for (int i=0;i<105;i++){
		for (int j=0;j<2;j++){
			for (int k=0;k<4;k++){
				dp[i][j][k]=0;
			}
		}
	}

//Operate for 0-digit.
	dp[0][0][0] = 0;
	dp[0][0][1] = 1;
	dp[0][0][2] = 0;
	dp[0][0][3] = 0;
	dp[0][1][0] = 0;
	dp[0][1][1] = int(n[0]-'0')-1;
	dp[0][1][2] = 0;
	dp[0][1][3] = 0;

	for (int i=1;i<n.length();i++){
		int x = int(n[i]-'0');
		if (x!=0){
			dp[i][0][1] = 0;
			dp[i][0][2] = dp[i-1][0][1];
			dp[i][0][3] = dp[i-1][0][2];

			dp[i][1][1] = dp[i-1][0][1]+dp[i-1][1][1]+9;
			dp[i][1][2] = dp[i-1][0][2]+dp[i-1][1][2]+dp[i-1][0][1]*(x-1)+dp[i-1][1][1]*9;
			dp[i][1][3] = dp[i-1][0][3]+dp[i-1][1][3]+dp[i-1][0][2]*(x-1)+dp[i-1][1][2]*9;
		}else {
			dp[i][0][1] = dp[i-1][0][1];
			dp[i][0][2] = dp[i-1][0][2];
			dp[i][0][3] = dp[i-1][0][3];
			dp[i][1][1] = dp[i-1][1][1]+9;
			dp[i][1][2] = dp[i-1][1][2]+dp[i-1][1][1]*9;
			dp[i][1][3] = dp[i-1][1][3]+dp[i-1][1][2]*9;
		}
//		cout << dp[i][0][3] << " " << dp[i][1][3] << endl;
	}


	cout << dp[n.length()-1][0][k]+dp[n.length()-1][1][k]<< endl;
}