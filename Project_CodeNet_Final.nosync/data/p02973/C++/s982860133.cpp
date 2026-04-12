#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100001;
int f[N];
int f1[N];
int d[N];
int n,ans,ans1;
int main()
{
	scanf("%d",&n);
	for(int i=n;i>=1;i--)
		scanf("%d",&d[i]);
	int len=1,len1=1;
	f[1]=f1[1]=d[1];
	for(int i=2;i<=n;i++)
	{
		if(f[len]>=d[i])
			f[++len]=d[i];
		else
		{
			int wz=upper_bound(f+1,f+1+len,d[i],greater<int >())-f;
			f[wz]=d[i];
		}
		if(f1[len1]<=d[i])
			f1[++len1]=d[i];
		else
		{
			int wz=upper_bound(f1+1,f1+1+len1,d[i])-f1;
			f1[wz]=d[i];
		}
	}
	printf("%d\n",len1);
	return 0;
}