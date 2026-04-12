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
LL dpT[3007][3007][2];
LL dp(int l, int r, int turn)
{
	if(l>r)
		return 0;
	if(dpT[l][r][turn]!=-1LL)
		return dpT[l][r][turn];
	if(turn)
		return dpT[l][r][turn]=min(dp(l+1,r,0)-arr[l],dp(l,r-1,0)-arr[r]);
	else
		return dpT[l][r][turn]=max(dp(l+1,r,1)+arr[l],dp(l,r-1,1)+arr[r]);
}



int main()
{
	//freopen("input.tXXt", "r", stdin);
	ios_base::sync_with_stdio(0);
	FILL(dpT,-1);
	cin >> n;
	FOR(i,0,n)
		cin >> arr[i];
	cout<<dp(0,n-1,0);
	return 0;
}
