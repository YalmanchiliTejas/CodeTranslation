#include <bits/stdc++.h>
#define INF 10000000
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
using namespace std;
int main()
{
	long n, q;
	cin >> n >> q;
	long p = 0;
	for(int i = 0; i < q; i++)
	{
		long t, k;
		cin >> t >> k;
		if(t == 1)
		{
			p += k;
		}
		else
		{
			cout << (p + k - 1) % n + 1 << endl;
		}
	}	
	return 0;
}
