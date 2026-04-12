#include <iostream>
using namespace std;

int manage(int init,int year)
{
	int type; double rate; int cost;
	cin >> type >> rate >> cost;

	int m = init;
	int intere = 0;

	for ( int i=0; i<year; i++ )
	{
		if ( type==0 )
		{
			intere += int(m*rate);
			m -= cost;
			//cout << m << endl;
		}
		else
		{
			m += int(m*rate) - cost;
			//cout << m << endl;
		}
	}

	return m + intere;
}

int main()
{
	int m; cin>>m;

	for ( int test=0; test<m; test++ )
	{
		int init; cin>>init;
		int year; cin>>year;
		int n; cin>>n;

		int ans = 0;
		for ( int i=0; i<n; i++ )
			ans = max(ans,manage(init,year));
		cout << ans << endl;
	}
}