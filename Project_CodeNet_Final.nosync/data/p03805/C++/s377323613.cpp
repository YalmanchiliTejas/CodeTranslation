#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int calc(int from, set<int> pass, vector<int>* e, int N)
{
	pass.insert(from);
	if (pass.size() == N)
	{
		return 1;
	}

	auto sum = 0;
	for (auto to : e[from])
	{
		if (pass.find(to) == pass.end())
		{
			sum += calc(to, pass, e, N);
		}
	}
	return sum;
};

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> e[9];
	for (auto i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	set<int> s;
	cout << calc(1, s, e, N) << endl;

	return 0;
}