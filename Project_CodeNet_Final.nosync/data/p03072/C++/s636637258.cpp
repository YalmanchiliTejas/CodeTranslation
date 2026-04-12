#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int h;
	cin >> h;
	int ans = 1;
	int maxh = h;
	for( int i = 1; i < n; ++i )
	{
		cin >> h;
		if( maxh <= h )	ans++;
		maxh = max( maxh, h );
	}

	cout << ans << endl;
	return 0;
}