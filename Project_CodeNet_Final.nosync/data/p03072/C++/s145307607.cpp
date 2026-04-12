#include <iostream>
using namespace std;
int main(void)
{
	int a ;
	cin >> a;
	int s[20];
	int i = 0;
  for (int i = 0 ; i < a ; i++)
	{
		cin >> s[i];
	}
	int ans = 1;
	for (int j = 0 ; j < a ; j++)
	{
		for (int p = 0; p < j ; p++)
		{
			if (s[j] < s[p])
			{
				break;
			}
			if (p == j-1)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}