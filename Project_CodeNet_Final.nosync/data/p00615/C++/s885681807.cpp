#include <iostream>
#include <cstring>

int max(int a, int b)
{
	if( a > b )
		return a;
	else
		return b;
}

void bsort(int a[], int lim)
{
	int tmp;

    for (int i = 0; i <= lim-1; i++)
        for (int j = lim; i < j; j--)
		{
            if (a[j-1] > a[j])
			{
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
            }
        }	
}

int main()
{
	int n, m, i;
	int out;
	int t[20002];

	while( std::cin >> n >> m , (n||m) )
	{
		std::memset( t, 0, sizeof(t));
		out = 0;

		for( i = 1; i <= n+m; i++)
		{
			std::cin >> t[i];
		}

		bsort( t, n+m );

		for( i = 0; i <= m+n; i++)
		{
			t[i] = t[i+1] - t[i];
		}
		for( i = 0; i <= m+n-1; i++)
		{
			out = max(out, t[i]);
		}

		std::cout << out << std::endl;
	}

	return 0;
}