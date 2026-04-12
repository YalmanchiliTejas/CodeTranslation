#include <bits/stdc++.h>
using namespace std;

int64_t n, x;
vector<int64_t> num, p_num;

int64_t f(int64_t index, int64_t k)
{
	if (x <= index)
	{
		return 0;
	}
	if (index + num[k] <= x)
	{
		return p_num[k] + (index + num[k] < x) + f(index + num[k] + 1, k);
	}
	else
	{
		return f(index + 1, k - 1);
	}
}

int main()
{
	cin >> n >> x;
	num.resize(n + 1);
	p_num.resize(n + 1);
	num[0] = 1;
	p_num[0] = 1;
	for (int i = 0; i < n; i++)
	{
		num[i + 1] = 2 * num[i] + 3;
		p_num[i + 1] = 2 * p_num[i] + 1;
	}
	cout << f(0, n) << endl;
	return 0;
}