#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m, res;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int cnt)
{
	if (cnt >= n)
	{
		res ++ ;
		return;
	}

	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (st[j]) continue;

		st[j] = true;
		dfs(j, cnt + 1);
		st[j] = false;
	}
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	
	while (m -- )
	{
		int a, b;
		cin >> a >> b;

		add(a, b), add(b, a);
	}
	
	st[1] = true;
	dfs(1, 1);
	
	cout << res << endl;
    return 0;
}