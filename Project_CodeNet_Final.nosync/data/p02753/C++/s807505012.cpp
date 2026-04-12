#include <bits/stdc++.h>

using namespace std;


/******************************************************************************
	Main
******************************************************************************/
int main()
{
	string s = "";
	cin >> s ;
	assert(s.size() == 3);

	string answer = (s == "AAA" || s == "BBB")? "No": "Yes";
	cout << answer << endl;

	return 0;
}
