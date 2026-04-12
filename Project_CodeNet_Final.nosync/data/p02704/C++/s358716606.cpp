#include <bits/stdc++.h>
using namespace std;

#define LL unsigned long long
#define pii pair<int, int>
#define mp make_pair

const int maxN = 505;

int n;
int oa[maxN + 1], ob[maxN + 1];
int G[maxN + 1][maxN + 1];
LL a[maxN + 1], b[maxN + 1];
LL ans[maxN + 1][maxN + 1];

inline void fail() { puts("-1"); exit(0); }

inline void work(int k)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) G[i][j] = -1;
	
	vector<pii> t1, t2;
	for(int i = 1; i <= n; i++)
		if(oa[i])
		{
			if(!(a[i] >> k & 1))
				for(int j = 1; j <= n; j++) G[i][j] = 0;
			else t1.push_back( mp(i, 1) );
		}
		else
		{
			if(a[i] >> k & 1)
				for(int j = 1; j <= n; j++) G[i][j] = 1;
			else t1.push_back( mp(i, 0) );
		}
	for(int j = 1; j <= n; j++)
		if(ob[j])
		{
			if(!(b[j] >> k & 1))
			{
				for(int i = 1; i <= n; i++)
					if(G[i][j] == 1) fail();
					else G[i][j] = 0;
			}
			else t2.push_back( mp(j, 1) );
		}
		else
		{
			if(b[j] >> k & 1)
			{
				for(int i = 1; i <= n; i++)
					if(G[i][j] == 0) fail();
					else G[i][j] = 1;
			}
			else t2.push_back( mp(j, 0) );
		}

	if(min(t1.size(), t2.size()) >= 2)
	{
		for(int i = 0; i < t1.size(); i++)
			for(int j = 0; j < t2.size(); j++)
				G[ t1[i].first ][ t2[j].first ] = (i + j) & 1;
		return;
	}
	if(!t1.size() || !t2.size())
	{
		for(int i = 0; i < t1.size(); i++)
		{
			int x = t1[i].first, v = t1[i].second, f = 0;
			for(int j = 1; j <= n; j++) f |= (G[x][j] == v);
			if(!f) fail();
		}
		for(int i = 0; i < t2.size(); i++)
		{
			int x = t2[i].first, v = t2[i].second, f = 0;
			for(int j = 1; j <= n; j++) f |= (G[j][x] == v);
			if(!f) fail();
		}
		return;
	}
	if(t1.size() == 1)
	{
		for(int i = 0; i < t2.size(); i++)
		{
			int x = t2[i].first, v = t2[i].second, f = 0;
			for(int j = 1; j <= n; j++) f |= (G[j][x] == v);
			if(!f) G[ t1[0].first ][x] = v;
		}
		int x = t1[0].first, v = t1[0].second, f = 0;
		for(int i = 1; i <= n; i++)
			if(G[x][i] != (v ^ 1)) G[x][i] = v, f = 1;
		if(!f) fail();
		return;
	}
	if(t2.size() == 1)
	{
		for(int i = 0; i < t1.size(); i++)
		{
			int x = t1[i].first, v = t1[i].second, f = 0;
			for(int j = 1; j <= n; j++) f |= (G[x][j] == v);
			if(!f) G[x][ t2[0].first ] = v;
		}
		int x = t2[0].first, v = t2[0].second, f = 0;
		for(int i = 1; i <= n; i++)
			if(G[i][x] != (v ^ 1)) G[i][x] = v, f = 1;
		if(!f) fail();
		return;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &oa[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &ob[i]);
	for(int i = 1; i <= n; i++) scanf("%llu", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%llu", &b[i]);

	for(int k = 0; k < 64; k++)
	{
		work(k);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(G[i][j]) ans[i][j] |= (1ull << k);
	}

	for(int i = 1; i <= n; i++, puts(""))
		for(int j = 1; j <= n; j++)
			printf("%llu ", ans[i][j]);
	return 0;
}
