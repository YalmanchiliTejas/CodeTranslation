#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define ri register int
#define max maxx
#define min minn
using namespace std;
template <class T> void in(T &x) {
	x = 0;
	bool f = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = 1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) x = -x;
}
inline int maxx(int x,int y) {
	return x>y?x:y;
}
inline int minn(int x,int y) {
	return x<y?x:y;
}
inline int gcd(int x,int y) {
	return !y?x:gcd(y,x%y);
}
int n,m,flag;
char a[120][120];
int mapp[120][120];
int sum1[120],sum2[120];
int vis[120][120];
int main() {
	in(n),in(m);
	for(ri i=1; i<=n; ++i) {
		scanf("%s",a[i]);
		for(ri j=0; j<m; ++j) {
			if(a[i][j]=='.')
				mapp[i][j+1]=1;
		}
	}

	/*for(ri i=1; i<=n; ++i) {
		for(ri j=1; j<=m; ++j)
			printf("%d ",mapp[i][j]);
		puts(" ");
	}*/

	for(ri i=1; i<=n; ++i)
		for(ri j=1; j<=m; ++j)
			sum1[i]+=mapp[i][j];
	for(ri i=1; i<=n; ++i)
		for(ri j=1; j<=m; ++j)
			sum2[j]+=mapp[i][j];
	/*for(ri i=1; i<=n; ++i)
		printf("%d ",sum1[i]);
	puts(" ");
	for(ri j=1; j<=m; ++j)
		printf("%d ",sum2[j]);*/
	for(ri i=1; i<=n; ++i)
		if(sum1[i]==m)
			for(int j=1; j<=m; ++j)
				vis[i][j]=1;
	for(ri j=1; j<=m; ++j)
		if(sum2[j]==n)
			for(ri i=1; i<=n; i++)
				vis[i][j]=1;
	for(ri i=1; i<=n; ++i) {
		flag=0;
		for(ri j=1; j<=m; ++j)
			if(!vis[i][j]) {
				flag=1;
				cout<<a[i][j-1];
			}
		if(flag)
			puts(" ");
	}
	return 0;
}
