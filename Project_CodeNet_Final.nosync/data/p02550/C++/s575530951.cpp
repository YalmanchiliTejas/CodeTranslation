#include<bits/stdc++.h>

using namespace std;
	long long n;int m;
long long yu[200100];
long long sum[200100];
int pos[200100];
int hs = -1;
int he = -1;
int main(){
	scanf("%lld%lld%d",&n,&yu[1],&m);//printf("~~~\n"); 
	for(int i = 0;i<=m;i++){
		pos[i]=-1;
	}
	pos[yu[1]]=1;sum[1] = yu[1];
	for(int i = 2;i <= m+1;i++){
		yu[i] = yu[i-1]*yu[i-1]%m;
		if(pos[yu[i]]==-1){
			pos[yu[i]]=i;
		} else {
			if(hs == -1) {
				hs = pos[yu[i]];
				he = i-1;
			} else {
				
			}
		}
		sum[i]=sum[i-1]+yu[i];
	}
	if(n<=m+1){
		printf("%lld\n",sum[n]);
		return 0;
	}
	
	long long ans = 0;
	
//	printf("%d  %d %d~%d\n",hs,he,yu[hs],yu[he+1]);
	ans = sum[hs-1];
	n-=hs-1;
	ans+=(n/(he-hs+1))*(sum[he]-sum[hs-1]);
	ans+=sum[hs-1+(n%(he-hs+1))]-sum[hs-1];
	printf("%lld\n",ans);
}