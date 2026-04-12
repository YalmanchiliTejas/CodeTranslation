#include <algorithm>
#include <iostream>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>

using std::set;
using std::multiset;
using std::tuple;
using std::vector;
using std::unordered_map;

int solve(int N, const vector<int> &A)
{
	multiset<int> set;
	for (int a : A)
	{
		if (!set.empty() && a > *set.cbegin())
		{
			auto it = set.lower_bound(a);
			set.erase(--it);
		}
		set.emplace(a);
	}
	return set.size();
}

int main(int argc, char *argv[])
{
	int N;
	std::cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) { std::cin >> A[i]; }
	std::cout << solve(N, A) << std::endl;
	return 0;
}
