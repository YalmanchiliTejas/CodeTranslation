#include <iostream>

using namespace std;

typedef long long ll;

ll n, x;
ll layer[55];

ll find(ll level, ll pos)
{
	if (level == 0) 
		return 1;
	if (pos == 1) 
		return 0;
	ll mid = layer[level] / 2;
	if (pos > 1 && pos < mid + 1) 
		return find(level - 1, pos - 1);
	if (pos == mid + 1) 
		return find(level - 1, layer[level - 1]) + 1;
	if (pos > mid + 1 && pos < layer[level]) 
		return find(level - 1, layer[level - 1]) + 
				find(level - 1, pos - 2 - layer[level - 1]) + 1;
	if (pos == layer[level]) 
		return find(level - 1, layer[level - 1]) * 2 + 1;
}

int main()
{
	cin >> n >> x;
	layer[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		layer[i] = layer[i - 1] * 2 + 3;
	}
	cout << find(n, x) << endl;
	return 0;
}