#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<memory.h>
using namespace std;
typedef long long ll;
const int Max = 1e2 + 5;
int lst[Max][Max];
int book[Max];
int res = 0, nn = 0;

void dfs(int n)
{
	book[n] = 1;
	int g = 0;
	for (int i = 1;i <= nn;i++) if (book[i]) g++;
	if (g == nn)
	{
		res++;
		return;
	}
	for (int i = 1;i <= nn;i++)
	{
		if (lst[n][i]&&book[i]==0)
		{
			dfs(i);
			book[i] = 0;
		}
	}
	return;
}

int main()
{
	int m;
	cin >> nn >> m;
	for (int i = 1;i <= m;i++)
	{
		int a, b;
		cin >> a >> b;
		lst[a][b] = 1;
		lst[b][a] = 1;
	}
	dfs(1);
	cout << res;

}