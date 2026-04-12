#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
char a[110][110];
int n,m,b[110],c[110];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m){
		scanf(" %c",&a[i][j]);
		if(a[i][j]=='#') b[i]|=1,c[j]|=1;
	}
	//rep(i,1,n) printf("%d",b[i]);puts("");
	rep(i,1,n){
		if(!b[i]) continue;
		rep(j,1,m) if(c[j]) printf("%c",a[i][j]);
		puts("");
	}
	return 0;
}