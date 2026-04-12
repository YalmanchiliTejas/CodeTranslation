#include <stdio.h>
#include <math.h>
#include <string.h>
typedef long long ll;
int main(int argc,int *argv[])
{
	char s[4];
	scanf("%s",s);
	if(s[0]==s[1] && s[0]==s[1] && s[1]==s[2])
		printf("No");
	else
		printf("Yes");
		return 0;
}