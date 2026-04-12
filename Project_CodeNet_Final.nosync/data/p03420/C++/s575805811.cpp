#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(){
	cin>>n>>k;long long res=0;
	if(k==0){
		printf("%lld",1ll*n*n);return 0;
	}
	for(int i=k+1;i<=n;++i){
		res+=(i-k)*(n/i);
		int x=n%i;
		res+=max(0,x-k+1);//cout<<res<<endl;
	}cout<<res;
	return 0;
}