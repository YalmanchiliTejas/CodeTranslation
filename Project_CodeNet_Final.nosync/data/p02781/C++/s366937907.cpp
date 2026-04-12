#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll dp1[100][4]; //小さい
ll dp2[100][4]; //ぴったり

int stoi(char c){
	return c - '0';
}

int main(){
	string s;
	int k;
	cin >> s >> k;

	if (s[0] == '0'){
		dp2[0][0] = 1;
	}else{ 
		dp1[0][0] = 1;
		dp1[0][1] = stoi(s[0]) - 1;
		dp2[0][1] = 1;
	}

	for (int i = 1; i < s.length(); i++){
		for (int j = 0; j <= k; j++){
			dp1[i][j] += dp1[i-1][j];
			if (s[i] == '0'){
				dp2[i][j] = dp2[i-1][j];
			}else{
				dp1[i][j] += dp2[i-1][j];
			}

			if (j == k) continue;
			dp1[i][j+1] += dp1[i-1][j]*9;
			if (s[i] != '0'){
				dp1[i][j+1] += dp2[i-1][j]*(stoi(s[i])-1);
				dp2[i][j+1] = dp2[i-1][j];
			}
		}
	}

	cout << dp1[s.length()-1][k] + dp2[s.length()-1][k] << endl;
	return 0;
}