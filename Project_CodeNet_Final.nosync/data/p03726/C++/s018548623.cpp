#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL) INF;

const int MAX = 100100;

VI g[MAX];
bool U[MAX];
int del[MAX];
queue<int> q;
int ST[MAX];


int main()
{
	//freopen("in.txt", "r", stdin);
	//ios::sync_with_stdio(false); cin.tie(0);

	int n;
	scanf("%d", &n);
	FOR (i, 0, n-1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].PB(y);
		g[y].PB(x);

		ST[x]++;
		ST[y]++;
	}

	FOR (i, 0, n)
	{
		if (ST[i] == 1)
		{
			q.push(i);
		}
	}

	while(SZ(q))
	{
	/*	FOR (i, 0, n)
		{
			cout<<i+1;
		}
		cout<<endl;
		FOR (i, 0, n)
		{
			if (del[i]) cout<<"d"; else
			if (U[i]) cout<<"u"; else
			cout<<"-";
		}
		cout<<endl;*/
		int x = q.front();
		q.pop();
		if (del[x]) continue;
		if (U[x]) continue;
		del[x] = true;

		int v = -1;
		FOR (i, 0, SZ(g[x]))
		{
			int to = g[x][i];
			if (del[to]) continue;
			if (U[to]) continue;
			v = to;
			break;
		}

	//	cout<<x<<' '<<v<<endl;

		if (v == -1)
		{
			cout<<"First"<<endl;
			return 0;
		}

		U[v] = true;
		FOR (i, 0, SZ(g[v]))
		{
			int to = g[v][i];
			ST[to]--;
			if (ST[to] == 1)
			{
				q.push(to);
			}
		}
	}

	cout<<"Second"<<endl;

}
