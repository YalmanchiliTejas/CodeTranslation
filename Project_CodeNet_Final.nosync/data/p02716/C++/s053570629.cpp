#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MP make_pair
#define EACH(i,c) for(auto i: c)
#define SORT(c) sort((c).begin(),(c).end())

#define ALL(a)  (a).begin(),(a).end()

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	vector<LL> A(N);
	REP(i, N) cin >> A[i];

	vector<vector<LL>> dp(3, vector<LL>(N, 0));
	dp[0][0] = A[0];

	FOR(i, 1, N){
		dp[0][i] = dp[0][i - 1];
		if(!(i & 1) && i != N - 1){
			dp[0][i] += A[i];
		}
		dp[1][i] = dp[1][i - 1];
		if(i & 1){
			dp[1][i] += A[i];
			if(3 <= i) dp[1][i] = max(dp[0][i - 3] + A[i], dp[1][i]);
		}
		dp[2][i] = dp[2][i - 1];
		if(!(i & 1)){
			dp[2][i] += A[i];
			if(3 <= i) dp[2][i] = max(dp[1][i - 3] + A[i], dp[2][i]);
			if(4 <= i) dp[2][i] = max(dp[0][i - 4] + A[i], dp[2][i]);
		}
		// cerr << i << " : " << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << endl;
	}

	if(N % 2){
		cout << max({dp[0][N - 3], dp[1][N - 2], dp[2][N - 1]}) << endl;
	}
	else{
		cout << max({dp[0][N - 2], dp[1][N - 1]}) << endl;
	}

	return 0;
}
