#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string ans = "No";
	int a = 0;
	int b = 0;
	for( int i = 0; i < S.size(); i++ ) {
		if( S[i] == 'A' ) a++;
		if( S[i] == 'B' ) b++;
	}
	if( a && b ) ans = "Yes";

	cout << ans << endl;
}
