#include <cstdio>
#define maxn 100010
using namespace std;
int n,d[maxn];
// d: 01: sheep; 1: wolf
char s[maxn];
int f(int a,int b,char ch) {
	if (b==0) {
		if (ch=='o')
			return a;
		else return 1-a;
	}
	else {
		if (ch=='o')
			return 1-a;
		else return a;
	}
}
int main() {
	scanf("%d %s",&n,s);
	bool t=true;
	for (int i=0;i<=1;i++) {
		for (int j=0;j<=1;j++) {
			d[1]=i; d[2]=j;
			for (int k=2;k<=n;k++) {
				d[k+1]=f(d[k-1],d[k],s[k-1]);
			}
			if (d[n+1]==d[1]&&f(d[n],d[1],s[0])==d[2]) {
				for (int k=1;k<=n;k++)
					if (d[k]==0)
						printf("S");
					else printf("W");
				printf("\n");
				t=false;
				break;
			}
		}
		if (!t)
			break;
	}
	if (t)
		printf("-1\n");
	return 0;
}