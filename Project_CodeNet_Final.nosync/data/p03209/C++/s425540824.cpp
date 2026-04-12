#include <iostream>
#include <algorithm>
using namespace std;




int main()
{
	int N;
	long long X;
	cin >> N >> X;
	
	long long a[51];
	a[0] = 1;

	for (int i = 1; i < 51; i++)
	{
		a[i] = 2 * a[i - 1] + 3;
	}

	long long p[51];
	p[0] = 1;

	for (int i = 1; i < 51; i++)
	{
		p[i] = 2 * p[i - 1] + 1;
	}

	long long ans = 0;

	for (int i = N; i >= 0; i--)
	{
		if (i == 0)
		{
			if (X == 0)
			{
				break;
			}
			else
			{
				ans += 1;
				break;
			}
		}
		else
		{
			if (X == 0)
			{
				break;
			}

			else if (1 <= X && X <= 1 + a[i - 1])
			{
				X--;
				continue;
			}

			else if (X == 2 + a[i - 1])
			{
				ans += p[i - 1] + 1;
				break;
			}

			else if (3 + a[i - 1] <= X && X <= 2 * a[i - 1] + 2)
			{
				ans += p[i - 1] + 1;
				X = X - a[i - 1] - 2;
				continue;
			}

			else
			{
				ans += 2 * p[i - 1] + 1;
				break;
			}
		}
	}

	cout << ans;
	return 0;

}