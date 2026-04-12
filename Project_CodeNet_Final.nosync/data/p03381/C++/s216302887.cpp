#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,a[N],b[N];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for (int i=1;i<=n;++i){
		int k=lower_bound(b+1,b+n+1,a[i])-b;
		if (k<=n/2) printf("%d\n",b[n/2+1]);
		else printf("%d\n",b[n/2]);
	}
	
	return 0;
}
			