#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
long long int n,x,nw,m;
scanf("%lld %lld %lld",&n,&x,&m);
long long int fst[100005]={};
long long int ss[100005]={};
nw=x;
int st=0,fi=0,flg=0;
for(int i=1;i<200000;i++)
{
	if(fst[nw]!=0){st=fst[nw]; fi=i-1;break;} //ループの開始はst,終了はfiで周期的
	fst[nw]=i;
	ss[i]=ss[i-1]+nw;
	//printf("%d %lld %lld\n",fst[nw],nw,ss[i]);
	nw=(nw*nw)%m;
	if(i==n){flg=1;break;}
}
//ループ前の部分:ss[st-1],ループの部分:ss[fi]-ss[st-1],ループの回数:(n-st+1)/(fi-st+1),
//ループ後の部分:zed=(n-st+1)%(fi-st+1)として ss[st-1+zed]-ss[st-1];
long long int ans=ss[st-1];
if(flg==0)
{
long long int lp=(n-st+1)/(fi-st+1);
long long int yo=(n-st+1)%(fi-st+1);
ans=ans+lp*(ss[fi]-ss[st-1]);
ans=ans+ss[st-1+yo]-ss[st-1];
}
else{ans=ss[n];}
printf("%lld",ans);
}
