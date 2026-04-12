#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

void Check(int i, int N, const vector<vector<int> >& graph, set<int>& v, int& ct)
{
	v.insert(i);
	if (v.size() == N)
	{
		++ct;
		v.erase(i);
		return;
	}
	auto& x = graph[i];
	for (auto& y : x)
	{
		if (v.find(y) == v.end())
		{
			Check(y, N, graph, v, ct);
		}
	}
	v.erase(i);
}
void ABC054C()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int> > graph(N+1);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	set<int> v;
	int ct = 0;
	Check(1, N, graph, v, ct);
	cout << ct << endl;
}

int main()
{
	ABC054C();
	return 0;
}