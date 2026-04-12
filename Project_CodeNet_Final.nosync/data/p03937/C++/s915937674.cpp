#include<cstdio>
int main(){
	int h,w;
	scanf("%d%d",&h,&w);
	int a[h][w]={};
	for(int i=0;i<h;i++){
		char s[w]={};
		scanf("%s",s);
		for(int j=0;j<w;j++){
			if(s[j]=='#')a[i][j]=1;
		}
	}
	int u=0;
	for(int i=0;i<w;i++){
		int y=0;
		for(int j=0;j<u;j++){
			y+=a[j][i];
		}
		if(y!=0){
			u=-1;
			break;
		}
		for(int j=u;j<h;j++){
			if(a[j][i]==0){
				u=j-1;
				break;
			}
			if(a[j][i]==1&&j==h-1){
				u=j;
				break;
			}
		}
		for(int j=u+1;j<h;j++){
			if(a[j][i]==1){
				u=-1;
				break;
			}
		}
	}
	if(u==-1)printf("Impossible");
	else printf("Possible");
	return 0;
}