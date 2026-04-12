#include<stdio.h>
#include<string.h>
int main(){
	int n,i,s,j,min;
	char a[100][100],b[100][130];
	memset(b,0,sizeof(b));
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
		s=strlen(a[i]);
		for(j=0;j<s;j++){
			b[i][a[i][j]]++;
		}
	}
	int flag=0;
	for(i='a';i<='z';i++){
		min=99999;
		for(j=0;j<n;j++){
			if(b[j][i]<min)
				min=b[j][i];
		}
		if(min!=0){
			flag=1;
			while(min--)
				printf("%c",i);
		}
	}
	if(flag!=1)
		printf("\n");
	return 0;
}