// by Balloons
#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=3e5+5;
int n,a[maxn],b[maxn];
map<int,int>mp;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int t1=b[n/2],t2=b[n/2+1];
	for(int i=1;i<=n;i++){
		if(i<=n/2)mp[b[i]]=t2;
		else mp[b[i]]=t1;
	}
	for(int i=1;i<=n;i++)printf("%d\n",mp[a[i]]);
	
	return 0;
}
