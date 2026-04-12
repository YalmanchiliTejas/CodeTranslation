#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_HW = 105;
char a[MAX_HW][MAX_HW];
bool wi[MAX_HW],wj[MAX_HW];

int main()
{
	int H,W;
	bool check = true;
	cin >> H >> W;
	rep(i,H)
	{
		check = true;
		rep(j,W)
		{
			cin >> a[i][j];
			if (a[i][j] == '#') check = false;
		}
		wi[i] = check;
	}

	rep(j,W)
	{
		check = true;
		rep(i,H)
		{
			if (a[i][j] == '#') check = false;
		}
		wj[j] = check;
	}

	rep(i,H)
	{
		bool output = false;
		rep(j,W)
		{
			if (!wi[i] && !wj[j])
			{
				cout << a[i][j];
				output = true;
			}
		}
		if (output) cout << endl;
	}
	return 0;
}