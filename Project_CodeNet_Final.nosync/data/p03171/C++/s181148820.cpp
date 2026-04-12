#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <stack>
#include <cmath>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (LL i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF*INF;
const int MAX = 400040	;
const long double PI = acos(-1.);
const double EPS = 1e-6;
LL mod = 1000LL * 1000 * 1000 + 7;

int n,k;
LL arr[3007];




int main()
{
	//freopen("input.tXXt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n;
	FOR(i,0,n)
		cin >> arr[i];
	vector<LL> x;
	FOR(i,0,n)
	{
		x.PB(arr[i]);
		while(SZ(x)>2 && x[SZ(x)-2]>x[SZ(x)-1] && x[SZ(x)-3]<x[SZ(x)-2])
		{
			LL t = x[SZ(x)-3]+x[SZ(x)-1]-x[SZ(x)-2];
			x.pop_back();
			x.pop_back();
			x.pop_back();
			x.PB(t);
		}
	}
	LL ans1 = 0, ans2 = 0;
	multiset<LL> foo;
	FOR(i,0,SZ(x))
		foo.insert(-x[i]);
	while(SZ(foo))
	{
		ans1-=*foo.begin();
		foo.erase(foo.begin());
		if(SZ(foo))
		{
			ans2-=*foo.begin();
			foo.erase(foo.begin());
		}
	}
	cout<<ans1-ans2;
	return 0;
}
