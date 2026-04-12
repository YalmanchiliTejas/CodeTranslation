#include<cstdio>
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a%(b+c)>=c) printf("%d",a/(b+c));
	else printf("%d",a/(b+c)-1);
	return 0;
}