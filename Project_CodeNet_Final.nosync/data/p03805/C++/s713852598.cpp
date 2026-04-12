#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <limits>
#include <iterator>
#include <cmath>
#include <numeric>
#include <stack>
#include <queue>
#include <cassert>
#include <forward_list>
#include <chrono>
#include <deque>
#include <list>
#include <random>
#include <cstdio>
#include <sstream>

using namespace std;
typedef pair<int, int> Vert;
int n, m;
vector<Vert> v;
vector<int> perm;

void permutation()
{
	int ans = 0;

	for (int i = 1; i < n+1; i++)
	{
		perm.push_back(i);
	}

	do
	{
		if (perm[0] != 1) { continue; }

		bool frag = true;
	
		for (int i = 0; i < n - 1; i++)
		{
			auto iter1 = find(v.begin(), v.end(), Vert(perm[i], perm[i + 1]));
			if (iter1 == v.end())
			{
				frag = false;
				break;
			}
		}
		
		if (frag) { ans++; }

	} while (next_permutation(perm.begin(), perm.end()));
	
	cout << ans << endl;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int j, k;
		cin >> j >> k;
		v.push_back(Vert(j, k));
		v.push_back(Vert(k, j));
	}

	permutation();

	return 0;
}