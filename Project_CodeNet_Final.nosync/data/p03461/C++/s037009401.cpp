/*d[x][y]=min{f[i][j]+i*x+j*y
  f[x][y]=max{d[i][j]-i*x-j*y*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {
		if (ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*neg;
}
const int maxn=300;
int f[maxn+5][maxn+5],d[maxn+5][maxn+5];
signed main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n(read()),m(read());
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			d[i][j]=read(); 
		}
	}
	for (int x=0;x<=100;++x) {
		for (int y=0;y<=100;++y) {
			for (int i=1;i<=n;++i) {
				for (int j=1;j<=m;++j) {
					f[x][y]=max(f[x][y],d[i][j]-i*x-j*y);
				}
			}
		}
	}
	int minv;
	for (int x=1;x<=n;++x) {
		for (int y=1;y<=m;++y) {
			minv=2147483647;
			for (int i=0;i<=100;++i) {
				for (int j=0;j<=100;++j) {
					minv=min(minv,f[i][j]+i*x+j*y);
				}
			}
			if (minv!=d[x][y]) {
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	puts("202 10401");
	for (int i=1;i<=100;++i) {
		printf("%lld %lld X\n",i,i+1);
	}
	for (int j=102;j<=201;++j) {
		printf("%lld %lld Y\n",j,j+1);
	}
	for (int i=0;i<=100;++i) {
		for (int j=0;j<=100;++j) {
			printf("%lld %lld %lld\n",i+1,202-j,f[i][j]);
		}
	}
	puts("1 202");
	return 0;
}
