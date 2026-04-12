#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, ans;
int vis[10];
vector <int> V[10];

void tap(int x)
{
	vis[x] = 1, a++;
	if(a == n) {
		ans++;
		return;
	}
	for(int i=0; i < V[x].size(); i++)
		if(vis[V[x][i]] == 0)
			tap(V[x][i]), a--, vis[V[x][i]] = 0;
}

int main()
{
	cin >> n >> m;
	
	for(int i=1; i <= m; i++)
		cin >> a >> b, V[a].push_back(b), V[b].push_back(a);
	
	a = 0, vis[1] = 1, tap(1);
	
	cout << ans;
}