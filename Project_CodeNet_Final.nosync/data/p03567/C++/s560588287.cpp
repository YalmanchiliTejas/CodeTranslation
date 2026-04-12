#include<bits/stdc++.h>
using namespace std;
char s[10];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	  if(s[i]=='A'&&s[i+1]=='C') return printf("Yes"),0;
	puts("No");
}