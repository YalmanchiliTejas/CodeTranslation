#include <stdio.h>
int main(void)
{
	int h,w,i,j,x[101],y[101];
	char s[101][101];
	scanf("%d%d",&h,&w);
	for(i=0; i<h; i++){
		scanf("%s",s[i]);
	}
	for(i=0; i<h; i++){
		for(j=0; j<w; j++){
			if(s[i][j]=='#'){
				x[i]=1;
				break;
			}
		}
	}
	for(i=0; i<w; i++){
		for(j=0; j<h; j++){
			if(s[j][i]=='#'){
				y[i]=1;
				break;
			}
		}
	}
	for(i=0; i<h; i++){
		for(j=0; j<w; j++){
			if(x[i]==1 && y[j]==1){
				printf("%c",s[i][j]);
			}
		}
		if(x[i]==1){
			puts("");
		}
	}
	return 0;
}