#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdlib>5
#include<string>
#include<algorithm>
#define LL long long
#define INF 1000000009
using namespace std;
const int maxn=110;
int main()
{
	int r,g,b;
	scanf("%d %d %d",&r,&g,&b);
	if((r*100+g*10+b)%4)
	printf("NO\n");
	else
	printf("YES\n");
}