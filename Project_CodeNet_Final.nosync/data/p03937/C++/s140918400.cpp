#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
char s[10];
void out()
{
	puts("Impossible");
	exit(0);
}

int main()
{
	//freopen("1.in","r",stdin);
	int last=1;
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
	{
		scanf("%s",s+1);
		rep(j,1,last-1)
		if(s[j]=='#')out();
		if(s[last]!='#')out();
		while(s[last+1]=='#')++last;
		rep(j,last+1,m)
		if(s[j]=='#')out();
	}
	if(last!=m)out();
	puts("Possible");
}