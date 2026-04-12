#include<iostream>

#include<cstdio>

#include<cstring>

#include<algorithm>

#include<cmath>

#include<set>

#include<vector>

using namespace std;
int n,c=0,ret=100;
int cnt[200];
char s[100];
int k;
int main(){
	//freopen("a.in","r",stdin);
	scanf("%d%s%d",&n,s+1,&k);
	ret=s[k]-'a';
	for(int i=1;i<=n;i++)if(s[i]-'a'==ret)printf("%c",s[i]);else printf("*");
}