#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define MOD 1000000007
using namespace std;
int main()
{
	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] == s[2] && s[0] == s[2]) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	return 0;
}