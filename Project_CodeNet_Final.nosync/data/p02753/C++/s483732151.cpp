#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	char s[5];
	cin >> s;
	int a = 0;
	int b = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == 'A')
			a++;
		else
			b++;
	}
		if (a > 0 && b > 0)
			cout << "Yes";
		else
			cout << "No";

}