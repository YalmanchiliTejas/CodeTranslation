#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <iostream>
#include <climits>
#include <cfloat>


using namespace std;

int main()
{
	map<int, int> solved;
	vector<int> rank;
	int a, b;
	while (true)
	{
		scanf("%d,%d\n", &a, &b);
		if (a == 0 && b == 0)
			break;
		solved.insert(make_pair(a, b));
		rank.push_back(b);
	}

	sort(rank.begin(), rank.end(), greater<int>());
	vector<int>::iterator e = unique(rank.begin(), rank.end());
	rank.erase(e, rank.end());

	while (scanf("%d\n", &a) != EOF)
	{
		int s = solved[a];
		int r;
		for (r = 1; r <= rank.size(); ++r)
		{
			if (s == rank[r-1])
				break;
		}
		printf("%d\n", r);
	}
	
	return 0;
}