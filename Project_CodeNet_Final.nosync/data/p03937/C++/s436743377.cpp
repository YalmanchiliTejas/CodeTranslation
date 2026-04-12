#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
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