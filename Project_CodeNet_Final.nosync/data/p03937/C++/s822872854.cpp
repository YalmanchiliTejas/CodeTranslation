#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,type=-1,cnt=0;
char arr[15][15];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",arr[i-1]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i-1][j-1]=='#'){
				++cnt;
			}
		}
	}
	x=0;
	y=0;
	while(1){
		if((arr[x][y+1]=='#'&&arr[x+1][y]=='#')||(arr[x][y+1]=='.'&&arr[x+1][y]=='.')){
			type=0;
//			printf("%d %d\n",x,y);
			break;
		}else{
			if(arr[x][y+1]=='#'){
				++y;
			}else ++x;
			//if(x<=15&&y<=15)
			//printf("%d %d\n",x,y);
		}
		if(x==n-1&&y==m-1){
			break;
		}
	}
	if(type==-1&&cnt==n+m-1){
		printf("Possible");
	}else printf("Impossible");
}