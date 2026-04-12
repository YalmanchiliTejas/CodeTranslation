#include<cstdio>
#include<cstring>
using namespace std;
bool err;
char ch[300];
int main()
{
	scanf("%s",ch);
	for(int i=0;i<strlen(ch)-1;i++)
	{
		if(ch[i]=='A'&&ch[i+1]=='C') 
		{
			err=1;break;
		}
	}
	if(err) printf("Yes\n");
	else printf("No\n");
}