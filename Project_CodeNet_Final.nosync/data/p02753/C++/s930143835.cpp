#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	sort(s.begin(), s.end());
	
	if(s[0] != s[2]) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}