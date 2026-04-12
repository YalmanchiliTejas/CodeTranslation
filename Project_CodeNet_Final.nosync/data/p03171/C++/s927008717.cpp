#include <iostream>
#include <algorithm>


const int MAXN = 3000;

long long change[MAXN];
long long bestScore[2][MAXN + 1][MAXN + 1];
bool seen[2][MAXN + 1][MAXN + 1];


long long findscore(int player, int start, int end)
{
	if (start == end)
			return 0;
	if (!seen[player][start][end])
	{
		seen[player][start][end] = true;
		bestScore[player][start][end] = std::max(change[start] - findscore(1 - player, start + 1, end), change[end - 1] - findscore(1 - player, start, end - 1));
	}

	return bestScore[player][start][end];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int dequeSize; std::cin >> dequeSize;
	for (int iElem = 0; iElem < dequeSize; iElem++)
			std::cin >> change[iElem];
	std::cout << findscore(0, 0, dequeSize) << '\n';

	return 0;
}
