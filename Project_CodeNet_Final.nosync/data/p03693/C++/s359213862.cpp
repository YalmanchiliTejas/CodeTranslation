#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main(void)
{
	char r[10];
	char g[10];
	char b[10];
	char s[20];
	cin >> r >> g >> b;
	sprintf (s,"%s%s%s",r,g,b);
	int i = atoi(s);
	if (i % 4 == 0)
	{
		cout << "YES";
	}
	else
	{
		cout<<"NO";
	}

	return 0;
}