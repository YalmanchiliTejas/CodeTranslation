#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int f[105][5][2],k;
char str[105];
int Calc(int now,int sumz,int flag){
	if(!now){
		if(sumz==k)return 1;
		return 0;
	}
	if(sumz>k)return 0;
	if(~f[now][sumz][flag])return f[now][sumz][flag];
	f[now][sumz][flag]=0;
	int &s=f[now][sumz][flag];
	int h=(flag?str[now]-'0':9);
	for(int i=0;i<=h;i++){
		s+=Calc(now-1,sumz+(i?1:0),flag&&i==h);
	}
	return s;
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%s%d",str+1,&k);
	int l=strlen(str+1);
	reverse(str+1,str+l+1);
	printf("%d\n",Calc(l,0,1));
}
