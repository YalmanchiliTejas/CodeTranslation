#include <bits/stdc++.h>
using namespace std;
long long a[200002],b[200002];
int main(){
	int sz=0,q=0,r=0;
	long long sum=0;
	scanf("%d",&sz); 
	for(int i=1;i<=sz;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sum-=a[1];
	for(int i=2;i<=sz;i++){
		b[i]=sum%(1000000007);
		sum-=a[i];
	}
	long long ans=0;
	int p=0;
	for(int i=1;i<=(sz-1);i++){
		p=i+1;
		ans+=(a[i]*b[p]);
		ans%=(1000000007);
	}

	printf("%lld",ans);
}