#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> ss(h);
	for (auto &&s : ss)
	{
		cin >> s;
	}

	vector<bool> jr(h, false), jc(w, false);
	for (int i = 0; i < h; i++)
	{
		bool f = true;
		for (int j = 0; j < w; j++)
		{
			f &= (ss[i][j] == '.');
		}

		jr[i] = f;
	}
	for (int j = 0; j < w; j++)
	{
		bool f = true;
		for (int i = 0; i < h; i++)
		{
			f &= (ss[i][j] == '.');
		}

		jc[j] = f;
	}

	for (int i = 0; i < h; i++)
	{
		if (jr[i])
		{
			continue;
		}

		for (int j = 0; j < w; j++)
		{
			if (jc[j])
			{
				continue;
			}

			cout << ss[i][j];
		}
		cout << endl;
	}

	return 0;
}