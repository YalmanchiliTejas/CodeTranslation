#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100001

int n,s[MAX_N],t[MAX_N];

int main(void)
{
	while(true)
	{
		cin >> n;
		if(n == 0)
			exit(0);
		for(int i = 1;i <= n;i++)
		{
			cin >> s[i];
		}
		for(int i = 1;i <= n;i++)
		{
			if(i % 2 == 1)
			{
				t[i] = s[i];
			}
			else
			{
				if(t[i-1] == s[i])
				{
					t[i] = s[i];
				}
				else
				{
					t[i] = s[i];
					for(int k = i - 1;t[k] != s[i] && k >= 1;k--)
					{
						t[k] = s[i];
					}
				}
			}
		}
		int count = 0;
		for(int i = 1;i <= n;i++)
		{
			if(t[i] == 0)
			{
				count++;
			}
		}
		cout << count << endl;
	}
}