#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,a[N],b[N];
int bin(int v){
	int l=1,r=n;
	for(;l<r;){
		int mid=(l+r)/2;
		if(v>b[mid])l=mid+1;else r=mid;
	}
	return l;
}
int main(){
	//freopen("aa.in","r",stdin);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+1+n);
	for(i=1;i<=n;++i){
		int k=bin(a[i]);
		if(k<=n/2)printf("%d\n",b[n/2+1]);
		else printf("%d\n",b[n/2]);
	}
	return 0;
}