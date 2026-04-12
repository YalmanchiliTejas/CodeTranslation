#include<bits/stdc++.h>
const int N=10;
using namespace std;
char s[N];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	if(len<=1)
	{
		printf("No\n");
		return 0;
	}
	int flag=0;
	for(int i=0;i<len-1;++i)
	{
		if(s[i]=='A'&&s[i+1]=='C') flag=1;
	}
    if(flag) printf("Yes\n");
    else printf("No\n");
	return 0;
}
