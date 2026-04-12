#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,i,j,x,ans;
int main(){
	scanf("%lld%lld",&n,&m);
	if(!m){
		printf("%lld",n*n);
		return 0;
	}
	for(i=1;i<=n-m;i++){
		x=i+m;
		ans+=n/x*i;
		if(n%x>=m)ans+=n%x-m+1;
	}
	printf("%lld",ans);
}