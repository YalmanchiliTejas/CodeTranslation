#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
#define ll long long
#define bl bool
#define nn printf("\n");
#define mod 1000000007

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int num; cin >> num;
	rep(i, num)
	{
		int mon = 0; cin >> mon;
		int yer = 0; cin >> yer;
		int dat = 0; cin >> dat;
		vector<int> ans(dat, 0);
		rep(j, dat)
		{
			int typ = 0; cin >> typ;
			double per = 0; cin >> per;
			int los = 0; cin >> los;
			int sum = mon, tmp = 0;
			rep(k, yer)
			{
				if (typ == 1){ sum += (int)(sum * per) - los; }
				else if (typ == 0)
				{
					tmp += (int)(sum * per);
					sum -= los;
				}
			}
			ans[j] = sum + tmp;
		}
		printf("%d\n", *max_element(all(ans)));
	}
	return 0;
}