#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back
#define x first
#define y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int N=100010;

int a[N],q[N],d[N];
vi e[N];
bool v[N],ok[N];

int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	int n;scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].pb(y);e[y].pb(x);
		d[x]++;d[y]++;
	}
	int f=1,r=0;memset(v,0,sizeof(v));
	for (int i=1;i<=n;i++) if (d[i]==1) {q[++r]=i;v[i]=1;}
	while (f<=r)
	{
		int m=0;
		for (int i=f;i<=r;i++)
		{
			for (vi::iterator p=e[q[i]].begin();p!=e[q[i]].end();p++)
				if (!v[*p])
				{
					if (ok[*p]) {puts("First");return 0;}
					a[++m]=*p;ok[*p]=1;
				}
		}
		for (int i=1;i<=m;i++) v[a[i]]=1;
		f=r+1;
		for (int i=1;i<=m;i++)
			for (vi::iterator p=e[a[i]].begin();p!=e[a[i]].end();p++)
				if (!v[*p])
				{
					d[*p]--;
					if (d[*p]==1) q[++r]=*p;
					if (d[*p]==0) {puts("First");return 0;}
				}
		for (int i=f;i<=r;i++) v[q[i]]=1;
	}
	puts("Second");
	return 0;
}
