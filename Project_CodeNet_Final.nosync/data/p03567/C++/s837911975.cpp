#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
#define Forr(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
inline void read(int &x)
{
    int p=1;
    x=0;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}
    x*=p;
}
char s[10];
int len;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	int flag=0;
	For(i,1,len-1)
		if(s[i]=='A'&&s[i+1]=='C')
		{
			flag=1;
			printf("Yes\n");
			break;
		}
	if(flag==0)printf("No\n");
	return 0;
}