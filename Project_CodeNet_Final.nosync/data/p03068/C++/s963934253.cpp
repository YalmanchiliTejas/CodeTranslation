#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n, k;
	string s;
	cin >> n >> s >> k;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == s[k-1])continue;
		s[i] = '*';
	}
	cout << s << endl;
	return 0;
}