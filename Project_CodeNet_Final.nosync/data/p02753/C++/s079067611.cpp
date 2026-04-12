#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin >> S;;

	char str[5] = { 'A' , 'B' };

	auto a = S.find("A");
	auto b = S.find("B");
	if ( a == string::npos || b == string::npos ) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}