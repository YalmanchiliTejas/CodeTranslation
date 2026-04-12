#include <cstdio>
#include <vector>
using namespace std;

vector<int> v[11];
bool visit[11];
int n, ans;

void back_tracking(int node, int all)
{
	int i;

	if (all == n)
	{
		++ans;
		return;
	}

	visit[node] = true;
	for (i = 0; i < v[node].size(); i++)
	{
		int next = v[node][i];

		if (!visit[next])
			back_tracking(next, all + 1);
	}
	visit[node] = false;
}

int main(void)
{
	int m, i, a, b;

	scanf("%d %d" ,&n, &m);
	while (m--)
	{
		scanf("%d %d" ,&a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	back_tracking(1, 1);

	printf("%d" ,ans);
	return 0;
}