#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define int long long
#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define MIN(a,b) ((a) < (b)) ? (a) : (b)
using namespace std;

struct tree
{
	int id;
	vector<int> next;

	tree(int id)
	{
		this->id = id;
	}
};

vector<int> v;
vector<tree> t;

signed main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n; i++)
	{
		v.push_back(i + 1);
	}
	for (int i = 0; i <= n; i++) //0も作る
	{
		t.push_back(tree(i));
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		t[a].next.push_back(b);
		t[b].next.push_back(a);
	}

	int cnt = 0;
	do
	{
		bool ok = true;
		int cur = 1;
		for (int i : v)
		{
			vector<int>& next = t[cur].next;
			if (find(next.begin(), next.end(), i) == next.end())
			{
				ok = false;
				break;
			}
			cur = i;
		}
		if (ok)
		{
			cnt++;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << cnt;
}
