#include<stdio.h>
#include<string.h>
 
int main(void){
 
	char a,b,c;
	int d,e,f;
	scanf("%c %c %c",&a,&b,&c);
 
	d = a - '0';
	e = b - '0';
	f = c - '0';
 
 
	if((a*100+b*10+c)%4==0){printf("YES\n");}
	else{printf("NO\n");}
 
	return 0;
}