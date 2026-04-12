#include <stdio.h>

int main(void) {
	char a[100][100];
	int i,j,r,c,cnt1,flag,cnt2,flag2,cntt;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf(" %c",&a[i][j]);
			
		}
	}
	for(i=0;i<r;i++){
		cnt1=0;
		for(j=0;j<c;j++){
			if(a[i][j]=='.')cnt1++;
			
		}
		if(cnt1==c){
			for(j=0;j<c;j++){
			a[i][j]='\0';
			}
		}
		
	}
	for(j=0;j<c;j++){
		cnt2=0;
		for(i=0;i<r;i++){
			if(a[i][j]=='.'||a[i][j]=='\0')cnt2++;
			
		}
		if(cnt2==r){
			for(i=0;i<r;i++){
			a[i][j]='\0';
			}
		}
		
	}
	for(i=0;i<r;i++){
		flag=0;
		cntt=0;
		for(j=0;j<c;j++){
			if(a[i][j]=='\0')cntt++;
		}	
		
		for(j=0;j<c;j++){
			if(a[i][j]!='\0'){
				//flag=1;
				printf("%c",a[i][j]);
			}
		}	 
		if(cntt<c)printf("\n");
		
			

			
			
		
		//if(flag==1)printf("\n");
	}
	return 0;
}
