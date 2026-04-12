#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>e[100007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int dfs(int w, int f)
{
	int cnt = 0;
	for(int i=e[w].size()-1;i>=0;i--)
		if (e[w][i] != f)
			if (dfs(e[w][i], w))
			{
				cnt++;
				if (cnt >= 2)
				{
					cout << "First" << endl;
					exit(0);
				}
			}
	return cnt ^ 1;
}
int main()
{
	n = read();
	for (int i = 1; i < n; i++)
	{
		int a = read(), b = read();
		e[a].push_back(b);
		e[b].push_back(a);
	}
	if (dfs(1, 0))cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}