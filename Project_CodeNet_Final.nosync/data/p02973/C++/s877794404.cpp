#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+9;
int len[maxn],a[maxn];

bool cmp(const int &a,const int &b){return a>b;};

int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",a+i);
	}
	len[1]=a[1];cnt=1;
	for(int i=2;i<=n;++i) {
		if(a[i]<=len[cnt]) len[++cnt]=a[i];
		else *upper_bound(len+1,len+cnt+1,a[i],cmp)=a[i];
	}
	printf("%d",cnt);
}
/*
7
4 3 1 2 3 4 3
*/