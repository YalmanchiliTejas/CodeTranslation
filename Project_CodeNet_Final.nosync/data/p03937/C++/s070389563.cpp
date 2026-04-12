#include<bits/stdc++.h>
using namespace std;
#define RI register int
int n,m,js;char ch[10];
int main()
{
	scanf("%d%d",&n,&m);
	for(RI i=1;i<=n;++i) {
		scanf("%s",ch+1);
		for(RI j=1;j<=m;++j) js+=(ch[j]=='#');
	}
	if(js==n+m-1) puts("Possible");
	else puts("Impossible");
	return 0;
}
