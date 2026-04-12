#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()

const int MOD = 1e9 + 7;
const int N = 10001;
const int D = 100;
char s[N];
int dp[N][D][2];

void add_self(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int d;
	scanf("%s%d", s, &d);

	int n = strlen(s);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			int k = s[i] - '0';
			add_self(dp[i+1][(j+k)%d][0], dp[i][j][0]);
			for (int x = 0; x < k; x++)
				add_self(dp[i+1][(j+x)%d][1], dp[i][j][0]);
			for (int x = 0; x < 10; x++)
				add_self(dp[i+1][(j+x)%d][1], dp[i][j][1]);
		}
	}
	int answer = dp[n][0][0] + dp[n][0][1] - 1;
	if (answer < 0) answer += MOD;
	printf("%d\n", answer);
}
