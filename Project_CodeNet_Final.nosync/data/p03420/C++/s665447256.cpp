#include <bits/stdc++.h>
using namespace std;
int main(){
  	long long N,K;
  	cin>>N>>K;
  	long long ans=0;
  	if(!K){
    	cout<<N*N<<endl;
    	return 0;
  	}
  	for(long long i=K+1;i<=N;i++){
    	ans+=((N+1)/i)*(i-K);
    	long long temp=(N+1)/i;
    	if(N+1-i*temp-K>0){
      		ans+=(N+1-i*temp-K);
    	}
  	}
  	cout<<ans<<endl;
  	return 0;
}
 