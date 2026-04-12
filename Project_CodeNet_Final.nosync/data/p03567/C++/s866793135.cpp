#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10;
char s[N];

int main()
{
	int flag=0;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<n;++i)
		if(s[i]=='A'&&s[i+1]=='C')	flag=1;
	if(flag)	puts("Yes");
	else	puts("No");	
	return 0;
}