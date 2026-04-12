#include<bits/stdc++.h>
using namespace std;

int a[1000];

int main(){
	int i,j,m,n,t,s,k,ans = 0;
	scanf("%d",&k);
	for(i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=k;i++){
		bool f = true;
		for(j=1;j<=i-1;j++){
			if(a[j]>a[i])f = false;
		}
		if(f)ans++;
	}
	printf("%d",ans);
	return 0;
} 
