#include <bits/stdc++.h>
using namespace std;
const int N=12;
char a[N][N];
int main (){
	int n,m;scanf ("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf ("%s",a[i]+1);
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cnt+=(a[i][j]=='#');
	puts((cnt==n+m-1)?"Possible":"Impossible");
	return 0;
}