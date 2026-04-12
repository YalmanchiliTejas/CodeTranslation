#include <cstdio>
int H,W,a[210][210],f[210][210][210];
bool vis[210][210][210];
int F(int x1,int y1,int x2,int y2){
	if(x1>=H||y1>=W||x2>=H||y2>=W)return 0;
	if(x1==H-1&&y1==W-1&&x2==H-1)return a[x1][y1];
	if(vis[x1][y1][x2])return f[x1][y1][x2];
	vis[x1][y1][x2]=1;
	int&g=f[x1][y1][x2];
	g=0;
	for(int d1=0;d1<2;d1++){
		for(int d2=0;d2<2;d2++){
			int tmp=F(x1+d1,y1+1-d1,x2+d2,y2+1-d2);
			if(tmp>g)g=tmp;
		}
	}
	g+=x1==x2&&y1==y2?a[x1][y1]:a[x1][y1]+a[x2][y2];
	return g;
}
int main(){
	scanf("%d%d",&H,&W);
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)scanf("%d",a[i]+j);
	printf("%d\n",F(0,0,0,0));
}