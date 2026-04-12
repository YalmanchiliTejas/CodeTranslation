#include<iostream>

using namespace std;

int main()
{
	int x, y, z;
	int cnt = 1,res;
	int flag = 0;

	cin >> x >> y >> z;

	while (1)
	{
		res = x - ((y*cnt) + (z*(cnt + 1)));
		if (res >= 0)
		{
			cnt++;
		}
		else
		{
			break;
		}
	}
	cout << cnt-1 << endl;

}