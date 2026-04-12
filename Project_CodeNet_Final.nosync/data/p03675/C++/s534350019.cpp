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
const int INF=0x7ffffff;
const int magic=348;
const int zero=200;

deque<int> q;
int n;
int a[200048];

int main ()
{
	int i;
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	bool f=true;
	for (i=1;i<=n;i++)
	{
		if (f) q.push_back(a[i]); else q.push_front(a[i]);
		if (f) f=false; else f=true;
	}
	if (f)
		while (!q.empty())
		{
			printf("%d ",q.front());
			q.pop_front();
		}
	else
		while (!q.empty())
		{
			printf("%d ",q.back());
			q.pop_back();
		}
	printf("\n");
	return 0;
}