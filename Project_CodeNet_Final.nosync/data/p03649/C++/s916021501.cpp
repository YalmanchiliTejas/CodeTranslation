#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
#define INF int(1e9)
#define N 50
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
typedef pair<int, int> P;
typedef pair<pair<P, P>, P>PP;
typedef long long LL;
LL n, sum;
LL a[N];
vector<LL> sm, bi;
bool judge()
{
	REP(i, n)
		if (a[i] > n - 1)
			return false;
	return true;
}
int solve(LL ans)
{
	LL sum = 0, s;
	REP(i, n)
	{
		s = a[i] / n;
		sum += s;
		a[i] %= n;
		a[i] -= s;
	}
	REP(i, n)
	{
		a[i] += sum;
	}
	judge() ? printf("%lld\n", ans + sum) : solve(ans + sum);
}
int main()
{
	cin >> n;
	REP(i, n)
		cin >> a[i];
	sort(a, a + n);
	judge() ? printf("0\n") : solve(0);
	return 0;
}