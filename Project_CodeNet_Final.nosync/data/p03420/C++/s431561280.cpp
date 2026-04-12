#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<iostream>
#define ll long long
int main()
{
	ll a,b,k,n,i;
	ll x,y;
	ll sum=0;
	scanf("%lld%lld",&n,&k);
	if(k==0)		//分开考虑，如果一起考虑，会出错误 
	{
		printf("%lld\n",n*n);
		return 0;
	}
	for(b=k+1;b<=n;b++)
	{
		x=b-k;			//从k到b-1总共多少个数,这也是a<b的情况】
		//从上面那个式子可以推出1---b一共有x个数；显然这个可以联想到1--n
		//联想有多少个b就是n/b;然后再判断就行了
		// 1-b有x是的，所以有b-x个数字不是的，这个方便等下处理最后几位数字
		 sum+=n/b*x;		
		 //最后还剩下n%b个数；
		 if(n%b>b-x-1)	//防止加个负数
		 	sum+=n%b-b+1+x; 
	//	printf("b-%d  sum-%d\n",b,sum);
	}
	printf("%lld\n",sum);
	return 0;
}