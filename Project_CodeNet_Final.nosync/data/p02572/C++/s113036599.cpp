#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF ((1<<30)-1)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()


#define MOD 1000000007

int n;
int a[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, n)cin >> a[i];


	long long s = 0;
	rep(i, n)s += a[i];
	long long ans = 0;

	s %= MOD;
	rep(i, n) {
		s -= a[i];
		s = (s + MOD) % MOD;

		ans += a[i] * s;
		ans %= MOD;
	}


	cout << ans << endl;

	return 0;
}
