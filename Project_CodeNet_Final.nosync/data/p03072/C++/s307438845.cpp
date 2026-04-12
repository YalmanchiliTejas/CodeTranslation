#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define re register
#define ll long long
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
int main()
{
	int n=gi(),mx=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=gi();
		if(x>=mx)ans++;
		mx=max(mx,x);
	}
	printf("%d\n",ans);
	return 0;
}
