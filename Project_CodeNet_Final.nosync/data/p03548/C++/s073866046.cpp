#include<bits/stdc++.h>
#define xlson kx<<1, xl, mid
#define xrson kx<<1|1, mid+1, xr
#define ylson ky<<1, yl, mid
#define yrson ky<<1|1, mid+1, yr
#define MAXN 1005
#define mem(a) memset(a, 0, sizeof(a))

using namespace std;

int main(void)
{
	int x,y,z;
	cin>>x>>y>>z;
	x-=z;
	printf("%d",x/(y+z));
	return 0;
}