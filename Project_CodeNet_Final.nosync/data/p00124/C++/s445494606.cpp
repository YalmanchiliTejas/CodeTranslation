#include <iostream>
#include <string>
using namespace std;
struct {string n; int w, l, d, p;} t[10], x;
int main()
{
	int n, i, j, b=0;
	while (cin >> n, n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> t[i].n >> t[i].w >> t[i].l >> t[i].d;
			t[i].p = t[i].w * 3 + t[i].d;
		}
		if (b < 0) cout << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n-1; j++)
			{
				if (t[j].p < t[j+1].p)
				{
					x = t[j];
					t[j] = t[j+1];
					t[j+1] = x;
				}
			}
		}
		for (i = 0; i < n; i++)
			cout << t[i].n << "," << t[i].p << endl;
		b--;
	}
}