#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9123372036854775807
#define MOD 100000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
using namespace std;

//余裕についてdp?
int main() {
	int N; cin >> N;
	vi A(N);
	rep(i, N) {
		cin >> A[i];
	}
	vector<vector<ll>> dp(N, vll(3,-ll_INF)); //dp[i][j] jは余裕を表す

	if (N == 2) {
		cout << max(A[0], A[1]) << endl;
	}
	else if (N == 3) {
		cout << max({ A[0], A[1], A[2] }) << endl;;
	}
	else {
		dp[0][0] = A[0];
		dp[0][1] = -ll_INF;
		dp[0][2] = -ll_INF;

		dp[1][0] = A[1];
		dp[1][1] = A[0];
		dp[1][2] = -ll_INF;

		dp[2][0] = A[2];
		dp[2][1] = A[1];
		dp[2][2] = A[0];

		for (int i = 3; i < N; i++) { // 0 Origin
			if (i % 2 == 1) { // 1 Origin and Even nubmer indexed  A
				dp[i][2] = -ll_INF;
				dp[i][1] = dp[i - 1][2] + A[i - 1];
				dp[i][0] = max(dp[i - 1][2], dp[i - 1][1]) + A[i];
			}
			else {
				dp[i][2] = dp[i - 1][1];
				dp[i][1] = dp[i - 1][0];
				dp[i][0] = max({ dp[i - 2][0],dp[i - 2][1],dp[i - 2][2] }) + A[i];
			}
		}

		cout << max({ dp[N - 1][0],dp[N - 1][1],dp[N - 1][2] }) << endl;
	}
	
}