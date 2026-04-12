#include <iostream>
#include <cstdlib>

using namespace std;

int main ( void )
{
	int n, t, e;
	
	while (cin >> n >> t >> e)
	{
		int ans = -1;
		
		for (int i = 1; i <= n; i += 1)
		{
			int in, a, b;
			cin >> in;
			a = abs((t / in) * in - t);
			b = abs((t / in + 1) * in - t);
			
			if (a <= e || b <= e)	ans = i;
		}
		
		cout << ans << endl;
	}
	return 0;
}