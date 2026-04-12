#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}



///////////////////////////



int main() {

	string s;
	ll K;
	cin >> s >> K;

	ll d = s.size();

	ll n[200];

	repn(i, d) {
		n[i] = s[i - 1] - '0';
	}
	
	ll dp[200][2][4] = {};//上からi桁、未満フラグ、0でないものの個数

	dp[0][1][0] = 1;

	repn(i, d) {
		rep(j, 4) {
			dp[i][0][j] = dp[i - 1][0][j];
			if (n[i] != 0) { dp[i][0][j] += dp[i - 1][1][j];}
			else { dp[i][1][j] = dp[i - 1][1][j]; }
		}

		repn(j, 3) {
			dp[i][0][j] += 9 * dp[i - 1][0][j - 1];
			if (n[i] != 0) {dp[i][0][j]+= (n[i] - 1) * dp[i - 1][1][j - 1]; }
			if (n[i] != 0) {
				dp[i][1][j] += dp[i - 1][1][j - 1];
			}

			
		}

	}


	cout << dp[d][0][K] + dp[d][1][K];





	system("PAUSE");

}
