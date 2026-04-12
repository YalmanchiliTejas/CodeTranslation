#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans = 0;
vector<int> p;
vector<vector<int>> nodes;

// pos : 次に決める要素の場所
// mask : 決まっていない値の集合(bit)
void dfs(int pos, int mask)
{
	//順列が一つ見つかった場合
	if (pos == N)
	{
		// 始めの頂点から始まっていない場合終了
		if (p[0] != 0)
			return;

		for (int i = 0;i < N - 1;i++)
		{
			// 道が無い場合終了
			if (nodes[p[i]][p[i + 1]] == 0)
				return;
		}

		// 条件を満たしている場合
		ans++;

		return;
	}

	for (int i = 0;i < N;i++)
	{
		//残りの順列(mask)に i があるかどうか
		if (mask & (1 << i))
		{
			// 次の要素をiにする
			p[pos] = i;

			// 決まった要素をmaskから取り除いて次を調べる
			dfs(pos + 1, (mask ^ (1 << i)));
		}
	}
}

int main()
{
	int M;
	cin >> N >> M;
	p.resize(N);
	nodes.resize(N);

	for (int i = 0;i < N;i++)
		nodes[i].resize(N, 0);
	
	for (int i = 0;i < M;i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		nodes[a][b] = 1;
		nodes[b][a] = 1;
	}


	dfs(0, (1 << N) - 1);

	cout << ans << endl;

	return 0;
}
