#include<cstdio>
#include<algorithm> 
#include<cstring>
#define LL long long
using namespace std;
bool f=false;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
char s[10]; 
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<n;i++)
		if(s[i]=='A'&&s[i+1]=='C')f=true;
	if(f)printf("Yes");
	else printf("No");
	return 0;
}