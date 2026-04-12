#include<stdio.h>

int strlen(char *a){for(int i=0;;i++)if(a[i]=='\0')return i;}

int strcmp(char *a,char *b){
	for(int i=0;i<7;i++)if(*(a+i)!=*(b+i))return 0;
	return 1;
}

char a[105][105];
int h,w;
int dR[105],dC[105],dRS=0,dCS=0;

int main(){
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++)scanf("%s",a[i]);
	for(int i=0;i<h;i++){
		int f = 0;
		for(int j=0;j<w;j++)if(a[i][j]=='#'){
			f=1;
			break;
		}
		if(f==0){
			dR[dRS++]=i;
		}
	}
	for(int i=0;i<w;i++){
		int f = 0;
		for(int j=0;j<h;j++)if(a[j][i]=='#'){
			f=1;
			break;
		}
		if(f==0){
			dC[dCS++]=i;
		}
	}
	for(int i=0;i<h;i++){
		int af=0;
		for(int k=0;k<dRS;k++)if(dR[k]==i)af=1;
		if(af==1)continue;
		for(int j=0;j<w;j++){
			int f = 0;
			for(int k=0;k<dCS;k++)if(dC[k]==j)f=1;
			if(f==1)continue;;
			printf("%c",a[i][j]);
		}
		puts("");
	}

}
