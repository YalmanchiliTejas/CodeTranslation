#include "bits/stdc++.h"

using namespace std;

void solve()
{
	char x, y, ans;
	int N;
	cin >> N;
	cin >> x >> y;
	if (y == 'F' && x == 'T')
	{
		x = 'F';
	}
	else x = 'T';
	for (int i = 0; i < N - 2; i++)
	{
		cin >> y;
		if (y == 'F' && x == 'T')
		{
			x = 'F';
		}
		else x = 'T';
	}
	cout << x << endl;
}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

