#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<cmath>
//#include<algorithm>
#define debug1 cout<<"?"<<endl;
#define debug2 cout<<"?"<<i<<endl;
#define PII pair<int,int>
typedef long long ll;
const int maxn=1e4+9;
const double pi=acos(-1);
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double ep=1e-7;
using namespace std;
char s[maxn];
int len;
inline ll dfs(int pos,int cnt)
{
	if(cnt==0)return 1;
	if(len-pos+1<cnt)return 0;
	int num=s[pos]-'0';
	if(!num)return dfs(pos+1,cnt);
	ll base=1,ans;
	for(int i=0;i<cnt-1;i++)base=base*9*(len-pos-i);
	if(cnt==3)base/=2;
	ans=base,base=1;
	if(len-pos+1==cnt)
	{
		return (num-1)*ans+dfs(pos+1,cnt-1);
	}
	for(int i=0;i<cnt;i++)base=base*9*(len-pos-i);
	if(cnt==2)base/=2;
	if(cnt==3)base/=6;
	return (num-1)*ans+base+dfs(pos+1,cnt-1);
}
int main()
{
	int i,j,k;
	scanf("%s%d",s+1,&k);
	len=strlen(s+1);
	printf("%lld\n",dfs(1,k));
}