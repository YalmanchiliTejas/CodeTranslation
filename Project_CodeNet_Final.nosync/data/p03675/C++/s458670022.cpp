#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int M=200005;
int n,a[M];
int ans[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n&1){
		int l=n/2+1,r=n/2+2;
		for(int i=1;i<=n;i+=2)ans[l--]=a[i];
		for(int i=2;i<=n;i+=2)ans[r++]=a[i];
	}else {
		int l=n/2+1,r=n/2;
		for(int i=1;i<=n;i+=2)ans[l++]=a[i];
		for(int i=2;i<=n;i+=2)ans[r--]=a[i];
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);putchar('\n');
	return 0;
}