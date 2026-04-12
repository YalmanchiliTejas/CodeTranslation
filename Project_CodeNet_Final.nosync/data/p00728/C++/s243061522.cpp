#include <iostream>
#include <algorithm>

int N;

int getScore(int A[])
{
	int maxA, minA, lenA, total {};
	lenA = N - 2;
	maxA = *std::max_element(A, A + N);
	minA = *std::min_element(A, A + N);
	for (int i {}; i < N; ++i)
		total += A[i];
	total = total - minA - maxA;
	
	int score;
	score = total / lenA;
	return score;
}

int main()
{
	while (std::cin >> N && N > 0)
	{
		int a[N];
		for (int i {}; i < N; ++i)
			std::cin >> a[i];
		std::cout << getScore(a) << std::endl;
	}
}
