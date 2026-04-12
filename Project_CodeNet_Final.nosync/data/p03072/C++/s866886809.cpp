
#include <bits/stdc++.h>
using namespace std;

int main()
{
int i;
int N;
int H;
int iCnt;
int iPre;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> N;
	cin >> iPre;

	iCnt = 1;
	for( i = 1; i < N; i++ )
	{
		cin >> H;

		if( iPre <= H )
		{
			iCnt++;
			iPre = H;
		}
	}

	cout << iCnt << endl;

	return 0;
}
