#include <iostream>

using namespace std;

int n, q;
bool v[100010], used[100010];

void magic(int i)
{
	if (v[i] && !used[i])
	{
		//v[i] = 0;

		if (i - 1 >= 1)
		{
			v[i - 1] = 1;
			used[i - 1] = 1;
		}

		if (i + 1 <= n)
		{
			v[i + 1] = 1;
			used[i + 1] = 1;
		}
	}
}

int main()
{
	v[1] = 1;
	cin >> n >> q;
	int ballpos = 1;
	for (int i = 1; i <= q; i++)
	{
		magic(ballpos);
		int a, b;
		cin >> a >> b;
		if (a == ballpos)
			ballpos = b;
		else if (b == ballpos)
			ballpos = a;
		swap(v[a], v[b]);
		swap(used[a], used[b]);
		magic(ballpos);
	}

	int nr = 0;
	for (int i = 1; i <= n; i++)
		nr += v[i];

	cout << nr;

	return 0;
}