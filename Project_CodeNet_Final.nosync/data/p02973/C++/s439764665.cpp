#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int n;
int A[M],tmp[M];
int C[M];
void add(int x,int d){
	for(;x;x^=x&-x)C[x]=max(C[x],d);
}
int sum(int x){
	int ret=0;
	for(;x<=n;x+=x&-x)ret=max(ret,C[x]);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		tmp[i]=A[i];
	}
	sort(tmp+1,tmp+1+n);
	int sz=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++)A[i]=lower_bound(tmp+1,tmp+1+sz,A[i])-tmp;
	int ans=0;
	for(int i=1;i<=n;i++){
		int ret=sum(A[i])+1;
		ans=max(ans,ret);
		add(A[i],ret);
	}
	printf("%d\n",ans);
	return 0;
}
