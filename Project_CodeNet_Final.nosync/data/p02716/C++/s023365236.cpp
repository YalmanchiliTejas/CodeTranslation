
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<complex>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#include <numeric>
using namespace std;
using Complex = complex<double>;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1145141919810364364LL;
double PI = acos(-1.0);
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)


ll dp[202020][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<ll>A(N);
	for (int i = 0; i < N; i++)cin >> A[i];

	dp[1][0] = -inf;
	dp[1][1] = A[0];
	dp[2][0] = A[1];
	dp[3][0] = A[2];
	dp[3][1] = A[0] + A[2];
	for (int i = 4; i <= N; i++) {
		if (i % 2 == 0) {
			ll pre2 = dp[i-2][0];
			ll pre3 = dp[i-3][1];
			dp[i][0] = max(pre2,pre3) + A[i-1];
		}
		else {
			ll pre2_0 = dp[i-2][0];
			ll pre3_0 = dp[i-3][0];
			ll pre4_0 = dp[i-4][1];
			dp[i][0] = max(pre2_0,max(pre3_0,pre4_0)) + A[i - 1];
			dp[i][1] = dp[i-2][1] + A[i - 1];
		}
	}

	if (N % 2 == 0) {
		puts(max(dp[N][0],dp[N-1][1]));
	}
	else {
		puts(max(dp[N][0],max(dp[N-1][0],dp[N-2][1])));
	}

	return 0;
}