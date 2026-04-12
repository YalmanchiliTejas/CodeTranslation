#include<cstdio>
#include<iostream>
int main()
{ int a,b,c;
  while(scanf("%d%d%d",&a,&b,&c)==3)
    {  int x=a*100+b*10+c;
	   if(x%4==0) printf("YES\n");
	   else printf("NO\n"); 
	}
	return 0;
}