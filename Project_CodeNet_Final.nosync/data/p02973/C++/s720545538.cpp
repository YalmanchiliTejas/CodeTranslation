/*************************************************************************
	> File Name: 1.cpp
	> Author: Knowledge_llz
	> Mail: 925538513@qq.com 
	> Blog: https://blog.csdn.net/Pig_cfbsl 
	> Created Time: 2020/9/6 11:59:52
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define LL long long
using namespace std;
int read(){
	char x=getchar(); int u=0,fg=0;
	while(!isdigit(x)){ if(x=='-') fg=1; x=getchar(); }
	while(isdigit(x)){ u=(u<<3)+(u<<1)+(x^48); x=getchar(); }
	return fg?-u:u;
}
const int maxx=1e5+10;
int n,a[maxx],c[maxx],cnt=0;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	n=read();
	For(i,1,n){
		int u=read(),l=1,r=cnt,mid,x=0;
		while(l<=r){
			mid=(l+r)>>1;
			if(c[mid]>=u) l=mid+1;
			else{
				x=mid;
				r=mid-1;
			}
		}
		if(!x) c[++cnt]=u;
		else c[x]=u;
	}
	printf("%d\n",cnt);
	return 0;
}
