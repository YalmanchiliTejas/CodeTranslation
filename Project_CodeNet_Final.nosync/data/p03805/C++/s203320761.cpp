#include <bits/stdc++.h>
typedef long long int lint;

#define PI acos(-1)
#define INF64 1LL << 60
#define INF32 1 << 29
#define all(a) (a).begin(), (a).end()
#define INV ((long long int)1000000007)

using namespace std;

vector<vector<bool>> root;
lint N;
lint Search(lint count, set<lint> through, lint current)
{
	through.insert(current);

	if (through.size() == N)
		return count + 1;

	for (int i = 0; i < N; i++)
	{
		if (root[current][i] && through.count(i) == 0)
			count = Search(count, through, i);
	}
	through.erase(current);
	return count;
}
void execute()
{
	int M;
	cin >> N >> M;

	root = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int i = 0; i < M; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		root[tmp1 - 1][tmp2 - 1] = true;
		root[tmp2 - 1][tmp1 - 1] = true;
	}
	set<lint> through;

	cout << Search(0, through, 0) << endl;

	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	execute();

	int stop;
	cin >> stop;

	return 0;
}