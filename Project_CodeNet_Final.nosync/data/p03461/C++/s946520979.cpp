#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define N 305
#define db double
#define ll long long
int A,B,dist[12][12],f[N][N],d;
int cal(int a,int b)
{
	int res=0;
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++) res=max(res,dist[i][j]-i*a-j*b);
	return res;
}
int main()
{
	scanf("%d%d",&A,&B);
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++) scanf("%d",&dist[i][j]);
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++) f[i][j]=cal(i,j);
	for(int i=1;i<=A;i++)
		for(int j=1;j<=B;j++)
		{
			d=1e9;
			for(int i2=0;i2<=100;i2++)
				for(int j2=0;j2<=100;j2++)
					d=min(d,f[i2][j2]+i*i2+j*j2);
			if(d^dist[i][j]) {puts("Impossible");return 0;}
		}
	puts("Possible\n202 10401");
	for(int i=1;i<=100;i++) printf("%d %d X\n",i,i+1);
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)//if(f[i][j])
			printf("%d %d %d\n",i+1,j+102,f[i][j]);
	for(int i=1;i<=100;i++) printf("%d %d Y\n",102+i,101+i);
	puts("1 102");
	return 0;
}