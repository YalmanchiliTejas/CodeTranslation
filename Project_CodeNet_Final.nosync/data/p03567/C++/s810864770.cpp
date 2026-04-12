#include<cstdio>
#include<cstring>
using namespace std;

char s[100001];

int main()
{
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
		if(s[i]=='A'&&s[i+1]=='C')
		{
			printf("Yes");
			return 0;
		}
	printf("No");
}