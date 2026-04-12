#include<bits/stdc++.h>
#define pb push_back
#define ins insert
#define F first
#define S second
#define var auto
using namespace std;
typedef long long ll;
const int Max = 1e5 + 10;
const int Log = 20;
const int Mod = 1e9 + 7;
const ll INF = 1e18;

vector<int> N[Max];

bool white[Max];
int child[Max];
bool seen[Max];
int par[Max];
int h[Max];

void DFS(int v)
{
	seen[v] = true;
	for(var u : N[v])
		if(!seen[u])
		{
			par[u] = v;
			h[u] = h[v] - 1;
			DFS(u);
			child[v]++;
		}
}

bool erased[Max];

int main()
{
	int n;cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int a , b;cin >> a >> b;
		N[a].pb(b);
		N[b].pb(a);
	}
	if(n == 2)
	{
		cout << "Second\n";
		return 0;
	}

	set<pair<int,int> > leafs;

	int root = -1;
	for(int i = 1; i <= n ; i++)
		if(N[i].size() >= 2)
			root = i;

	DFS(root);

	for(int i = 1; i <= n ; i++)
		if(N[i].size() == 1)
			leafs.ins({h[i] , i});

	bool win = false;
	while(leafs.size())
	{
		if(n == 2)
			break;
		if(n == 1)
		{
			win = true;
			break;
		}

		var v = *leafs.begin();
		//cout << v.S << '\n';
		leafs.erase(leafs.begin());
		var p = par[v.S];
		if(child[p] >= 2)
		{
			win = true;
			break;
		}
		var pp = par[p];

		if(pp)
		{
			child[pp]--;
			if(child[pp] == 0)
				leafs.ins({h[pp] , pp});
		}
		n -= 2;
	}
	if(win)
		cout << "First\n";
	else
		cout << "Second\n";
}

