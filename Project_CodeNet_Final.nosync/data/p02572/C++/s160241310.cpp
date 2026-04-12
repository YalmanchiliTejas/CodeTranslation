//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<map>
#include<vector>
#include<cmath>
#include<fstream>
#include <set>
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
const int  MAXN =2e5+10;
const int mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf= 0x3f3f3f3f;
#define eps 1e-8
#define PI 3.1415926535898
#define lowbit(x) (x&(-x))
using namespace std ;
//getline(cin,s);
//set<ll>::iterator it;
//map<int,int>::iterator it;
//unordered_map
typedef long long ll;
//已AC 尝试去并查集 典型的权值并查集 再写一遍巩固并理解 
int n;
ll a[MAXN],sum[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
	    scanf("%lld",&a[i]);
	    sum[i]=sum[i-1]+a[i];
	    sum[i]%=mod;
	} 
	ll ans=0;
	for(int i=1;i<n;i++)
	{
		ll summ=(a[i]%mod*(sum[n]-sum[i])%mod)%mod;
		ans=(ans+summ+mod)%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}