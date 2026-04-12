#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


ll dp1[100][4];
ll dp2[100][4];

int ctoi(char c){
	return c - '0';
}

int main(){
	string s;
	int k;
	cin >> s >> k;

	dp1[0][1] = 1;
	dp2[0][0] = 1;
	dp2[0][1] = ctoi(s[0])-1;

	for (int i = 1; i < s.length(); i++){
		for (int j = 0; j <= 3; j++){
			if (ctoi(s[i]) == 0){
				dp1[i][j] += dp1[i-1][j];
				dp2[i][j] += dp2[i-1][j];
				if (j != 0){
					dp2[i][j] += dp2[i-1][j-1]*9;
				}
			}else{
				if (j != 0){
					dp1[i][j] += dp1[i-1][j-1];
					dp2[i][j] += dp1[i-1][j-1]*(ctoi(s[i])-1);
					dp2[i][j] += dp2[i-1][j-1]*9;
				}
				dp2[i][j] += dp2[i-1][j];
				dp2[i][j] += dp1[i-1][j];
			}
		}
	}
	cout << dp1[s.length()-1][k] + dp2[s.length()-1][k] << endl;
	return 0;
}