#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	string s; cin >> s;
	bool valid = (count(s.begin(), s.end(), 'A') >= 1) and (count(s.begin(), s.end(), 'B') >= 1);
	cout << (valid ? "Yes" : "No");
	return 0;
}