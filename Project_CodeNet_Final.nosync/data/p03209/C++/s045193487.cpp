#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef unsigned long long ll;
using namespace std;
ll len[55],p[55];//分别存放Burger的长度和肉饼的个数  
ll slove(ll n,ll x)
{
	if(n==0) return x;
	else if(x==0||x==1) return 0;
	else if(x==len[n]) return p[n];
	else if(x<=len[n-1]+1) return slove(n-1,x-1);
	else if(x<=len[n]-1) return 1+p[n-1]+slove(n-1,x-2-len[n-1]);
}
int main()
{
	len[1]=5;
	p[1]=3;
	for(int i=2;i<=51;i++) 
	{
		len[i]=2*len[i-1]+3;
		p[i]=2*p[i-1]+1;
	}
	ll n,x;
	cin>>n>>x;
	cout<<slove(n,x)<<endl;
	return 0;
}
/*
BPPPB  1级   5  3

B[BPPPB]P[BPPPB]B 2级  2*5+3   13  7

B[BBPPPBPBPPPBB]P[BBPPPBPBPPPBB]B 3级    2*(2*5+3)+3   29  15

BBBBPPPBPBPPPBBPBBPPPBPBPPPBBBPBBBPPPBPBPPPBBPBBPPPBPBPPPBBBB 4级  2*29+3   31
*/