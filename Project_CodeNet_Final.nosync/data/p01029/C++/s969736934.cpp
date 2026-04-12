#include <bits/stdc++.h>

int main()
{
	int V, E;
	scanf("%d%d", &V, &E);
	std::vector<std::list<int>> graph(V);
	std::vector<char> chara(V);
	for (auto& e: chara) scanf(" %c", &e);

	for (int i{}; i < E; i++)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		graph[s].push_back(t);
		graph[t].push_back(s);
	}
	for (int i{}; i < V; i++)
	{
		if (chara[i] != '?') continue;
		bool table[26]{};
		for (auto& e: graph[i])
			if (chara[e] != '?')
				table[chara[e] - 'a'] = true;
		for (int j{}; j < 26; j++)
			if (!table[j])
			{
				chara[i] = 'a' + j;
				break;
			}
	}
	for (auto& e: chara) putchar(e);
	putchar('\n');

	return 0;
}
