#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<bitset>
using namespace std;
#define ll long long
#define re register
#define mp make_pair
typedef pair<int,int> pii;
inline int gi()
{
	int sum=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
ll n,x; 
int main()
{
	scanf("%lld%lld",&n,&x);int tmp=n;ll len=1,ans=0;
	while(tmp--)len=(len<<1)+3;
	while(x&&n>=0)
	{
		if(x>=(len+1)/2)ans+=1ll<<n,x-=(len+1)/2;
		else x--;
		len=(len-3)/2;n--;
	}
	printf("%lld\n",ans); 
	return 0;
}
