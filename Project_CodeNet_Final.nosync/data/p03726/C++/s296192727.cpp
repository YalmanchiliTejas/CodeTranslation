#include <bits/stdc++.h>
using namespace std;

set<int> ch[100005];
bool mark[100005];
set<int> alive;
int n;

void kill(int x)
{
	alive.erase(x);
	for (int u: ch[x]) ch[u].erase(x);
	ch[x].clear();
}

int main()
{
	scanf("%d", &n);
	for (int i = 1;i < n;i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		--a, --b;
		ch[a].insert(b);
		ch[b].insert(a);
	}
	for (int i = 0;i < n;i++) alive.insert(i);
	while (alive.size() > 2)
	{
		vector<int> todo;
		for (auto it = alive.begin();it != alive.end();it++) if (ch[*it].size() == 1)
			todo.push_back(*it);
		vector<int> ext;
		for (int u: todo)
		{
			if (mark[*ch[u].begin()])
			{
				printf("First\n");
				return 0;
			}
			mark[*ch[u].begin()] = true;
			ext.push_back(*ch[u].begin());
		}
		for (int u: todo) kill(u);
		for (int u: ext) kill(u);
	}
	if (alive.size() == 1)
	{
		printf("First\n");
	} else
	{
		if (alive.empty() || ch[*alive.begin()].find(*alive.rbegin()) != ch[*alive.begin()].end()) printf("Second\n");
		else printf("First\n");
	}
	return 0;
}
