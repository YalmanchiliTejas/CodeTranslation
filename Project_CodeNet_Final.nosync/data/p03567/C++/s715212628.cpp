#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string ans = "Yes";
	if( S.find( "AC" ) == string::npos ) ans = "No";

	cout << ans << endl;
}
