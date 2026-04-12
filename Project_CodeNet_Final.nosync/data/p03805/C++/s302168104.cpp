#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, a, b, c[9][9]{};
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		c[a][b] = c[b][a] = 1;
	}

	int p[8], ans = 0;
	iota(begin(p), begin(p) + n, 1);
	do 
	{
		bool ok = true;
		for (int i = 0; i < n - 1; i++)
			if (!c[p[i]][p[i+1]])
				ok = false; 
		if (ok)
			ans++;
	} while (next_permutation(begin(p) + 1, begin(p) + n));

	cout << ans << endl;

}
