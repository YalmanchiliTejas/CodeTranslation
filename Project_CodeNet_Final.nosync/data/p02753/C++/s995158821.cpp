#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//#include<queue>
//#include<cmath>
//#include<algorithm>
//#define debug1 cout<<"?"<<endl;
//#define debug2 cout<<"?"<<i<<endl;
#define PII pair<int,int>
typedef long long ll;
const int maxn=1e2+9;
const double pi=acos(-1);
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double ep=1e-7;
using namespace std;
int main()
{
	char s[maxn];
	scanf("%s",s+1);
	int i,len=strlen(s+1),ju=0;
	for(i=2;i<=len&&!ju;i++)
	{
		if(s[i-1]!=s[i])ju=1;
	}
	if(ju)puts("Yes");
	else puts("No");
}