#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
char s[10][10];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	int x=1,y=1;
	while((x<n||y<m)&&(x<=n&&y<=m)){
		s[x][y]='%';
		if(s[x+1][y]=='#')++x;
		else++y;
	}
	s[n][m]='%';
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='#')return puts("Impossible"),0;
	puts("Possible");
	return 0;
}
