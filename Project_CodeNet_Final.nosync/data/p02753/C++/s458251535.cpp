#include <bits/stdc++.h>
using namespace std;

char s[5];

int main()
{
	scanf("%s",s);
	printf("%s\n",s[0]==s[1]&&s[0]==s[2]?"No":"Yes");
	return 0;
}