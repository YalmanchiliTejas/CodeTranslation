#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	string h[2] = {"qwertasdfgzxcvb", "yuiophjklnm"};
	char s[33];
	int n, r, i;
	while (cin >> s)
	{
		if (s[0] == '#') break;
		n = ((h[0].find(s[0], 0) != string::npos) ? 0 : 1);
		r = 0;
		for (i = 1; i < strlen(s); i++)
			if (h[n].find(s[i], 0) == string::npos)
				n = ((n == 0) ? 1 : 0), r++;
		cout << r << endl;
	}
}