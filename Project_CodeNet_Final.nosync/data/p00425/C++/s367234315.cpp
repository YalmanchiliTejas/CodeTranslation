#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	while (1)
	{
		int c;
		cin >> c;
		if (c == 0)break;
		vector<int>a(6);
		for (int b = 0; b < 6; b++)
		{
			a[b] = b + 1;
		}
		int s = 1;
		for (int d = 0; d < c; d++) {
			string e;
			cin >> e;
			vector<int>m(6);
			for (int n = 0; n < 6; n++) {
				m[n] = a[n];
			}
			switch (e[0]) {
			case 'N':a[0] = m[1]; a[1] = m[5]; a[4] = m[0]; a[5] = m[4]; break;
			case 'S':a[1] = m[0]; a[5] = m[1]; a[0] = m[4]; a[4] = m[5]; break;
			case 'E':a[0] = m[3]; a[2] = m[0]; a[3] = m[5]; a[5] = m[2]; break;
			case 'W':a[3] = m[0]; a[0] = m[2]; a[5] = m[3]; a[2] = m[5]; break;
			case 'R':a[1] = m[2]; a[2] = m[4]; a[3] = m[1]; a[4] = m[3]; break;
			case 'L':a[2] = m[1]; a[4] = m[2]; a[1] = m[3]; a[3] = m[4]; break;
			}
			s += a[0];
		}
		cout << s << endl;
	}
}