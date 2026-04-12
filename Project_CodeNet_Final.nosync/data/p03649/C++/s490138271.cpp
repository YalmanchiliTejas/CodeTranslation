#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <deque>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define LL long long
#define Pair pair<int,int>
#define LOWBIT(x) x & (-x)
using namespace std;

const int MOD=1e9+7;
const LL INF=1e16+1000;
const int magic=348;

int n;
LL a[148];

int main ()
{
	int i,j;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	LL ans=0;
	do
	{
		bool f=false;
		for (i=1;i<=n;i++)
			if (a[i]>=n)
			{
				f=true;
				LL d=a[i]-(n-1);
				LL ss;
				if (d%n==0) ss=d/n; else ss=d/n+1;
				ans+=ss;
				a[i]-=ss*n;
				for (j=1;j<=n;j++)
					if (i!=j) a[j]+=ss;
			}
		if (!f) break;
	}
	while (true);
	cout<<ans<<endl;
	return 0;
}