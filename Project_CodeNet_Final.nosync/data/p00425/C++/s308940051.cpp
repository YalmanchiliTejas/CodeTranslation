#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main()
{
	while (1)
	{
		int ans = 1, k, ue = 1, migi = 3, hidari = 2;

		cin >> k;
		if (k == 0)break;
		while (k--)
		{
			string a;
			int s, d;
			cin >> a;
			if (a == "North")
			{
				s = ue;
				ue = hidari;
				hidari = 7 - s;
			}
			else if (a == "East")
			{
				s = ue;
				ue = 7 - migi;
				migi = s;
			}
			else if (a == "West")
			{
				s = ue;
				ue = migi;
				migi = 7 - s;
			}
			else if (a == "South")
			{
				s = ue;
				ue = 7 - hidari;
				hidari = s;
			}
			else if (a == "Left")
			{
				s = migi;
				migi = hidari;
				hidari = 7 - s;
			}
			else if (a == "Right")
			{
				s = hidari;
				hidari = migi;
				migi = 7 - s;
			}
			ans += ue;
		}
		cout << ans << endl;






	}

	return 0;
}