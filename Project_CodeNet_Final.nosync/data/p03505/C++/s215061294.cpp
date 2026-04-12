#include<cstdio>
long long a, b, c, flag;
int main()
{
	scanf("%lld%lld%lld",&a, &b, &c);
	if(b>=a){printf("1\n");return 0;}
	else if(c >= b) {printf("-1\n");return 0;}
	if((a-b)%(b-c) >= 1) flag = 1;
	printf("%lld\n",((a-b)/(b-c)+flag)*2+1);
	return 0;
}