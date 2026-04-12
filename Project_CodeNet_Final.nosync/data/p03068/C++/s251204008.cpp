#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdbool.h>
#include<math.h>
#include<sstream>
#include<math.h>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<bitset>
typedef long long ll;
#define N (1000000000+7)
#define INF 1e10
using namespace std;
typedef pair<ll, ll> P;

ll dp[50][2] = { 0 };
int main(void) {
	int n, k;
	string s;
	cin >> n >> s >> k;
	for (int i = 0;i < n;i++) {
		if (s[k - 1] != s[i]) {
			s[i] = '*';
		}
	}
	cout << s << endl;
}