#include <iostream>
using namespace std;

int main()
{
	int n = 0, k = 0;
	string s = "";
	cin >> n >> s >> k;
	char nonchange = s[k - 1];
	for (int i = 0; i < n; i++)
	{
		if (s[i] != nonchange)
			s[i] = '*';
	}
	cout << s;
}