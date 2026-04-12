#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	pair <string, int> score[10] , tmp;
	int n, w, l, d;
	int flg = 0;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		if (flg != 0) cout << endl;

		for (int i = 0; i < n; i++)
		{
			cin >> score[i].first >> w >> l >> d;
			score[i].second = w * 3 + d;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j > i; j--)
			{
				if (score[j].second > score[j-1].second)
				{
					tmp=score[j];
					score[j] = score[j - 1];
					score[j - 1] = tmp;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			cout << score[i].first << "," << score[i].second << endl;
		}
		flg++;
	}

	return 0;
}