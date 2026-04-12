#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack> 
#include <map>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

#define pb 					push_back

template<typename T,typename S>
ostream& operator <<(ostream& os, pair<T, S> input) {
	os<<"("<<input.first<<", "<<input.second<<")";
	return os;
}

template<typename T>
ostream& operator <<(ostream& os, vector<T> input) {
	for(auto t: input)
		os << t <<" ";

	return os;
}


string s;
int D;

long long dp [10002][3][102];
long long MOD = 1e9 + 7;
int solve(int in, int isPref, int mod) {
	if(in == s.size()) {
		if(0 == mod)
			return 1;
		else
			return 0;
	}

	if(dp[in][isPref][mod]!=-1)
		return dp[in][isPref][mod];
	int r = 9;

	if(isPref)
		r =s[in]-'0';

	long long ans =0;
	for(int d = 0; d<=r; d++){
		int rmod = (mod - d)%D;
		if(rmod <0)
			rmod +=D;

		assert(rmod >=0 && rmod < D);
		ans += solve(in + 1, isPref && (d==r), rmod);
		ans%=MOD;
	}

	return dp[in][isPref][mod] = ans;

}
int main() {
    //ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> s;

	cin >> D;
	long long ans = (solve(0, 1, 0) -1 +MOD)%MOD;
	cout << ans<<"\n";
	return 0;
}

