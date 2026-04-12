#include <bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0;
	register bool f=0;
	register char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=305;
int d[15][15],f[maxn][maxn];
int n,m;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) d[i][j]=read();
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++)
				f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
			}
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=1;y<=m;y++){
			int sum=1000000007;
			for(int i=0;i<=100;i++){
				for(int j=0;j<=100;j++){
					sum=min(sum,f[i][j]+i*x+j*y);
				}
			}
			if(sum!=d[x][y]){
				puts("Impossible");
				return 0;
			}
		}
	}
	cout<<"Possible"<<endl;
	cout<<300<<" "<<10401<<endl;
	int tot=0;
	for(int i=1;i<=100;i++){
		printf("%d %d X\n",i,i+1);
		tot++;
	}
	for(int j=300;j>=201;j--){
		printf("%d %d Y\n",j-1,j);
		tot++;
	}
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			printf("%d %d %d\n",i+1,300-j,f[i][j]);
			tot++;
		}
	}
	puts("1 300");
    return 0;
}