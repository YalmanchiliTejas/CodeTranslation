#include<cstdio>
using namespace std;
int H,W;
char g[105][105];
bool c[105][2];
int main(){
	scanf("%d%d",&H,&W);
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++){
			scanf(" %c",&g[i][j]);	
			if(g[i][j]=='#')c[i][0]=true;
		}
	for(int j=1;j<=W;j++)
		for(int i=1;i<=H;i++)
			if(g[i][j]=='#'){
				c[j][1]=true;
				break;
			}
	for(int i=1,f;i<=H;i++){
		f=0;
		for(int j=1;j<=W;j++)
			if(c[i][0]&&c[j][1]){
				printf("%c",g[i][j]);	
				f=1;
			}
			if(f)putchar('\n');
		}
}