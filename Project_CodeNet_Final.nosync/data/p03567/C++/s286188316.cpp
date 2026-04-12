#include<bits/stdc++.h>
using namespace std;
typedef int sign;
typedef long long ll;
#define For(i,a,b) for(register sign i=(sign)a;i<=(sign)b;++i)
#define Fordown(i,a,b) for(register sign i=(sign)a;i>=(sign)b;--i)
const int N=100+5;
bool cmax(sign &a,sign b){return (a<b)?a=b,1:0;}
bool cmin(sign &a,sign b){return (a>b)?a=b,1:0;}
template<typename T>T read()
{
	T ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch-'0'),ch=getchar();
	return ans*f;
}
void file()
{
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
}
void work()
{
	char s[10];
	scanf("%s",s);
	For(i,0,strlen(s)-2)
	{
		if(s[i]=='A'&&s[i+1]=='C'){printf("Yes\n");return;}
	}
	printf("No\n");
}
int main()
{
	//file();
	work();
	return 0;
}
