#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<stdio.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define INF 1e9

int main()
{
	ll n, k;
	cin >> n >> k;
	ll ans = 0;

	REP(i, k + 1, n + 1) {
		ans += (n / i) * (i - k);
		ans += max((ll)0, (n % i) - k + 1);
	}
	cout << (k == 0 ? (n * n):ans) << endl;
	return 0;
}