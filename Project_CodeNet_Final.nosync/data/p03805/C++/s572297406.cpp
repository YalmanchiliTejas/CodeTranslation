#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
	vector<int> next;

};

int calc(vector<node> &n, int index, vector<bool> &map)
{
	map[index] = true;
	int result = 0;
	if (all_of(map.begin(), map.end(), [](auto v) {return v; }))
	{
		result = 1;
	}
	for (auto&& v : n[index].next)
	{
		if (!map[v])
			result += calc(n, v, map);

	}
	map[index] = false;
	return result;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<node> a(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1].next.push_back(y - 1);
		a[y - 1].next.push_back(x - 1);
	}
	vector<bool> map(n,false);
	cout << calc(a, 0, map) << endl;
}
