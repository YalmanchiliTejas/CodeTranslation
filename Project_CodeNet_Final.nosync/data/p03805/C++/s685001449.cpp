#include <iostream>
#include <vector>
#include <array>
using namespace std;

constexpr int MaxN = 8;
constexpr int MaxM = (MaxN * (MaxN - 1)) / 2;

int answer = 0;
array<vector<int>, MaxN> edges;

int Count(int s, int check)
{
	if (check == answer)
	{
		return 1;
	}

	int sum = 0;
	for (auto candidate : edges[s])
	{
		int check_cand = 1 << candidate;
		if ((check & check_cand) != 0)
		{
			continue;
		}

		sum += Count(candidate, check | check_cand);
	}

	return sum;
}

int main()
{
	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		answer |= (1 << i);
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int sum = Count(0, 1);

	cout << sum << endl;

	return 0;
}