#include<cstdio>
typedef long long ll;
int main()
{
    ll k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    if(k<=a) return printf("1\n"),0;
    if(a<=b) return printf("-1\n"),0;
    ll ans=(k-a)/(a-b);
    if((k-a)%(a-b)) ans=2*ans+3;
    else ans=2*ans+1;
    printf("%lld\n",ans);
	return 0;
}