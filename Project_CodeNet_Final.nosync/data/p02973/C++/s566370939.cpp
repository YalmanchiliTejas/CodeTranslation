#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
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
const ll MAX = 400000;



ll seq(int N,ll A[MAX]) {
	vector<ll> dp;//長さiの列の末端の最小値

	repn(i, N) {
		auto j = upper_bound(dp.begin(),dp.end(),A[i]);
		int dist = j - dp.begin();

		if (dist < dp.size()) { dp[dist] = A[i]; }
		else { dp.push_back(A[i]); }

	}

	return dp.size();
}




int main() {

	int N;
	cin >> N;

	ll A[MAX];
	repn(i, N) {
		cin >> A[i];
		A[i] *= -1;
	}

	cout << seq(N, A);

	system("PAUSE");


}