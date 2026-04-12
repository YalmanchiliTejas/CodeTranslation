#include<stdio.h>
int main(){
	char a[3];
	scanf("%s",a);
	bool f=0,b=0;
	if(a[0]=='A') f=1;
	else if(a[0]=='B') b=1;
	if(a[1]=='A') f=1;
	else if(a[1]=='B') b=1;
	if(a[2]=='A') f=1;
	else if(a[2]=='B') b=1; 
	if(f==1&&b==1) printf("Yes");
	else printf("No");
	return 0;
}