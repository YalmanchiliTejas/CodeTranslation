#include<bits/stdc++.h>
using namespace std;
int Min(int x,int y){
	return x<y?x:y;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==0){
		printf("%lld\n",n*(long long)n);
		return 0;
	}
	long long ans=0;
	int cnt;
	for(int i=k+1;i<=n;i++){
		cnt=n/i;
		ans=ans+(n-cnt*k-Min(n%i,k-1));
	}
	printf("%lld\n",ans);
	return 0;
}
