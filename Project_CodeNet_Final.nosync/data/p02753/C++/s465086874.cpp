#include <bits/stdc++.h>
using namespace std;
char str[10];
int main()
{
	cin>>str;
	if((str[0]=='A'&&str[1]=='A'&&str[2]=='A')||
	(str[0]=='B'&&str[1]=='B'&&str[2]=='B'))
		puts("No");
	else
		puts("Yes");
    return 0;
}