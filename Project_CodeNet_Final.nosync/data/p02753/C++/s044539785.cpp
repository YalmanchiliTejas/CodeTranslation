#include <stdio.h>
char s[5];
int main(){
	int i,cnta=0,cntb=0;
	scanf("%s",s);
	for(i=0;i<3;i++)
		if(s[i]=='A')cnta++;
		else cntb++;
	if(cnta==3||cntb==3)printf("No\n");
	else printf("Yes\n");
	return 0;
}