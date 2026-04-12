#include <bits/stdc++.h>
using namespace std;

int n, m, row[110], col[110];
char a[110][110];
bool vr[110], vc[110];

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
			if (a[i][j] == '#')
				++row[i], ++col[j];
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!row[i] && !col[j])
				vr[i] = 1, vc[j] = 1;
	for (int i = 1; i <= n; ++i)
		if (!vr[i])
		{
			for (int j = 1; j <= m; ++j)
				if (!vc[j])
					cout << a[i][j];
			cout << endl;
		}

}