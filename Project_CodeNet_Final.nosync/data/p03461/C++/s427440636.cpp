#include<bits/stdc++.h>
using namespace std;

const int maxn=300;
int a,b,d[maxn][maxn],w[maxn][maxn];

int main(){
	cin>>a>>b;
	for(int x=1;x<=a;++x)
		for(int y=1;y<=b;++y){
			cin>>d[x][y];
			for(int i=0;i<=100;++i)
				for(int j=0;j<=100;++j)
					if(w[i][j]<d[x][y]-i*x-j*y)
						w[i][j]=d[x][y]-i*x-j*y;
		}
	for(int x=1;x<=a;++x)
		for(int y=1;y<=b;++y){
			int dis=1e9;
			for(int i=0;i<=100;++i)
				for(int j=0;j<=100;++j)
					if(dis>i*x+j*y+w[i][j])
						dis=i*x+j*y+w[i][j];
			if(dis!=d[x][y]){
				puts("Impossible");
				return 0;
			}
		}
	puts("Possible");
	printf("%d %d\n",202,2*100+101*101);
	for(int i=1;i<=100;++i)
		printf("%d %d X\n",i,i+1);
	for(int i=1;i<=100;++i)
		printf("%d %d Y\n",i+102,i+101);
	for(int i=0;i<=100;++i)
		for(int j=0;j<=100;++j)
			printf("%d %d %d\n",i+1,j+102,w[i][j]);
	puts("1 102");
	return 0;
}