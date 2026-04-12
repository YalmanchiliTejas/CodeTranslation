#include<cstdio>
int main()
{
	int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int x=100*a+10*b+c;
        x%=4;
        if(!x) printf("YES\n");
        else printf("NO\n");
	return 0;
}