#include <stdio.h>
char txt[4];
int main(){
	scanf("%s",txt);
	int A=0,B=0;
	for(int i=0;i<3;i++){
		A+=txt[i]=='A';
		B+=txt[i]=='B';
	}
	printf("%s",A>0&&B>0?"Yes":"No");
}