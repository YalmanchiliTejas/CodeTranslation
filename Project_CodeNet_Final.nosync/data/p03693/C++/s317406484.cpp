#include<cstdio>
int main(){
	int a,b,c,d;
	scanf("%d %d %d",&a,&b,&c);
	d=b*10+c;
	if(d%4==0)printf("YES");
		else printf("NO");
	return 0;
}