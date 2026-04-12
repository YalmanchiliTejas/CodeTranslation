#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	 long long ans=0;
	if(k==0){
		ans=(long long)n*n;
	}else{
			for(int i=k;i<=n;i++){
				
				ans+=(long long)(i-k)*(n/i);
				if(n%i>=k){
					ans+=n%i-k+1;
				}
			}
	}
	cout<<ans<<endl;
	return 0;
}