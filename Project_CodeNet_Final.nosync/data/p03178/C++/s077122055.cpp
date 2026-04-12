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

string s;
int d;
LL dpT[10000][2][100];
LL dp(int pos, int rivne, int ostacha)
{
	if(pos==SZ(s))
		return ostacha==0;
	if(dpT[pos][rivne][ostacha]!=-1)
		return dpT[pos][rivne][ostacha];
	if(rivne)
	{
		LL ans=0;
		FOR(i,0,(s[pos]-'0'))
		{
			ans=(ans+dp(pos+1,0,(ostacha+i)%d))%mod;
		}
		ans=(ans+dp(pos+1,1,(ostacha+s[pos]-'0')%d))%mod;
		return dpT[pos][rivne][ostacha]=ans;
	}
	else
	{
		LL ans=0;
		FOR(i,0,10)
		{
			ans=(ans+dp(pos+1,0,(ostacha+i)%d))%mod;
		}
		return dpT[pos][rivne][ostacha]=ans;
	}
}


int main()
{
	//freopen("input.tXXt", "r", stdin);
	ios_base::sync_with_stdio(0);
	FILL(dpT,-1);
	cin >> s >> d;
	cout<<(dp(0,1,0)+mod-1)%mod;
	return 0;
}
