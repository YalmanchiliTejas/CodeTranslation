#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k;
	string s;
	cin >> n >> s >> k;
	string str = "";
	char c = s[k-1];
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != c) str += '*';
		else str += s[i];
	}
	cout << str << endl;
	return 0;
}