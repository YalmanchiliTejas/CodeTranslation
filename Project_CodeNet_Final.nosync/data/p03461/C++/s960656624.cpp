#include<bits/stdc++.h>
#define int long long
inline int read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int k=1,kk=0;if (c=='-')c=getchar(),k=-1;
	while (c>='0'&&c<='9')kk=kk*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(int x){if (x<0)putchar('-'),x=-x;if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(int x){write(x);puts("");}
struct lsg{int x,y,z;}f[1000][1000];
int a,b,c[1000][1000],flag[1000][1000],fff[1000][1000],ii,jj,sum;
signed main(){
	a=read();b=read();for (int i=1;i<=a;i++)for (int j=1;j<=b;j++)c[i][j]=read();
	ii=jj=-1;
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++)
			for (int k=0;k<=100;k++){
				int ff=0,fff=0;if (ii==i&&jj==j)continue;
				for (int x=1;x<=a;x++)
					for (int y=1;y<=b;y++)if (c[x][y]>i*x+j*y+k)ff=1;
				if (ff)continue;
				for (int x=1;x<=a;x++)
					for (int y=1;y<=b;y++)
						if (c[x][y]==i*x+j*y+k)f[x][y].x=i,f[x][y].y=j,f[x][y].z=k,flag[x][y]=1,fff=1;
				if (fff)ii=i,jj=j;
			}
	for (int i=1;i<=a;i++)for (int j=1;j<=b;j++)if (!flag[i][j]){puts("Impossible");return 0;}
	puts("Possible");for (int i=1;i<=a;i++)for (int j=1;j<=b;j++)
		if (!fff[f[i][j].x][f[i][j].y])sum++,fff[f[i][j].x][f[i][j].y]=1;
	cout<<300<<' '<<200+sum<<endl;memset(fff,0,sizeof(fff));
	for (int i=1;i<=100;i++)cout<<i<<' '<<i+1<<' '<<'X'<<endl;
	for (int i=1;i<=100;i++)cout<<300-i<<' '<<300-i+1<<' '<<'Y'<<endl;
	for (int i=1;i<=a;i++)for (int j=1;j<=b;j++)
		if (!fff[f[i][j].x][f[i][j].y])
			cout<<f[i][j].x+1<<' '<<300-f[i][j].y<<' '<<f[i][j].z<<endl,fff[f[i][j].x][f[i][j].y]=1;
	cout<<1<<' '<<300<<endl;
}