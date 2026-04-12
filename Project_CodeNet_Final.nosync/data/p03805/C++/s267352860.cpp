#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[10];
int N,M;
int ans = 0;

void dfs(int a, int check)
{
	//cout << " visiting:" << a << " check:" << check << endl;
	if (check == (1 << N) - 1)
	{
		ans++;
		return;
	}

	rep(i,G[a].size())
	{
		if (!(check & (1 << G[a][i])))
		{
			int next_check = check + (1 << G[a][i]);
			//cout << "from:" << a;
			dfs(G[a][i],next_check);
		}
	}
}

int main()
{
	cin >> N >> M;
	rep(i,M)
	{
		int a,b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	/*
	rep(i,M)
	{
		rep(j,G[i].size())
		{
			cout << G[i][j];
		}
		cout << endl;
	}
	*/

	dfs(0,1);
	cout << ans << endl;
	return 0;
}