#include <stdio.h>

int main(){
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
int i,num=b;
for(i=1;i<=g;i++){
	num+=10;

}

	if(num%4==0){
		printf("YES");
	}else printf("NO");
}