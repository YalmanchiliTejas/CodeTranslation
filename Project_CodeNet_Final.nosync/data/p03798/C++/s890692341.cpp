#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 1e9 + 123;//786433;//998244353;
const double Pi = acos(-1);
const int p = 510200;
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
char a[100005];
char b[100005];

signed main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	b[1] = 'S';
	b[2] = 'S';
	for(int i = 3; i <= n; i++)
	{
		if(b[i - 1] == 'S')
		{
			if(a[i - 1] == 'o')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
		else
		{
			if(a[i - 1] == 'x')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
	}
	if(b[n] == 'S')
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
		else
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
	}
	else
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
		else
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
			
		}
	}
	b[1] = 'W';
	b[2] = 'S';
	for(int i = 3; i <= n; i++)
	{
		if(b[i - 1] == 'S')
		{
			if(a[i - 1] == 'o')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
		else
		{
			if(a[i - 1] == 'x')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
	}
	if(b[n] == 'S')
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
			
		}
		else
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
			
		}
	}
	else
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
			
		}
		else
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
	}
	b[1] = 'S';
	b[2] = 'W';
	for(int i = 3; i <= n; i++)
	{
		if(b[i - 1] == 'S')
		{
			if(a[i - 1] == 'o')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
		else
		{
			if(a[i - 1] == 'x')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
	}
	if(b[n] == 'S')
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}	
		}
		else
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
	}
	else
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
		else
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}	
			}
		}
	}
	b[1] = 'W';
	b[2] = 'W';
	for(int i = 3; i <= n; i++)
	{
		if(b[i - 1] == 'S')
		{
			if(a[i - 1] == 'o')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
		else
		{
			if(a[i - 1] == 'x')
			{
				b[i] = b[i - 2];
			}
			else
			{
				if(b[i - 2] == 'S')
				{
					b[i] = 'W';
				}
				else
				{
					b[i] = 'S';
				}
			}
		}
	}
	if(b[n] == 'S')
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
		else
		{
			if(a[1] == 'o')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
	}
	else
	{
		if(a[n] == 'o')
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] != b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
			
		}
		else
		{
			if(a[1] == 'x')
			{
				if(b[n - 1] == b[1])
				{
					for(int i = 1; i <= n; i++)
					{
						cout << b[i];
					}
					return 0;
				}
			}
		}
	}
	cout << -1;
}