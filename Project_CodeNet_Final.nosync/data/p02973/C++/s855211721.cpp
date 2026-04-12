#include <bits/stdc++.h>
using namespace std;
int n,d[100005],l,a[100005];
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	l=1;
	d[1]=a[n];
	for (int i=n-1; i>=1; i--){
		int tt=upper_bound(d+1,d+1+l,a[i])-d;
		if (tt>l){
			d[++l]=a[i];
		} 
		if (d[tt]>a[i]){
			d[tt]=a[i];
		} 
	}
	printf("%d",l);
}