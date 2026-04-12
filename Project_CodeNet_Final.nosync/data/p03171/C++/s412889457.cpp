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

const int N = 3000;
ll dp[N][N];
int a[N];

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) dp[i][i] = a[i];
	for (int x = 1; x < n; x++) {
		for (int i = 0; i + x < n; i++) {
			dp[i][i+x] = max(a[i] - dp[i+1][i+x], a[i+x] - dp[i][i+x-1]);
		}
	}
	printf("%lld\n", dp[0][n-1]);
}

