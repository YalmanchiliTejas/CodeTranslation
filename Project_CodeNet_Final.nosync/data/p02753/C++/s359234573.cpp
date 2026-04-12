#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
	char s[3];
	cin >> s[0] >> s[1] >> s[2];
	int a=0, b=0;
	for (int i = 0; i < 3; i++)
	{
		if (s[i] == 'A') a++;
		if (s[i] == 'B') b++;
	}
	if (a == 1 || b == 1) cout << "Yes";
	else cout << "No";
}