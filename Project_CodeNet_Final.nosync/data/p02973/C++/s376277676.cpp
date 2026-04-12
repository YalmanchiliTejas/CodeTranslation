#include<bits/stdc++.h>
using namespace std;
int n,A[1000010],Q[1000010],head=1,tail,ans,BIT[1000010],dp[1000010],num[1000010],m;
void Add(int i,int x){
	while(i>=1)BIT[i]=max(BIT[i],x),i-=i&-i;
}
int Query(int i){
	int res=0;
	while(i<=m)res=max(res,BIT[i]),i+=i&-i;
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]),num[i]=A[i];
	sort(num+1,num+1+n);
	m=unique(num+1,num+1+n)-num-1;
	for(int i=1;i<=n;i++)A[i]=lower_bound(num+1,num+1+m,A[i])-num;
	for(int i=1;i<=n;i++){
		int res=Query(A[i]);
		dp[i]=res+1;
		ans=max(ans,dp[i]);
		Add(A[i],dp[i]);
	}
	cout<<ans;
	return 0;
}