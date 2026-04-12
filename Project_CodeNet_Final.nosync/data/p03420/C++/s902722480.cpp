#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int main(){
    long long n,k;
    long long ans=0,tmp;
    cin>>n>>k;
	if(n*n<=1e8){
	  for(int i=1;i<=n;i++){
		  for(int j=1;j<=n;j++){
			 if(i%j>=k){
				ans++;
			 }
		 }
	  }
	} 
	else {
        for(long long i=k+1;i<=n;i++){
    	    tmp=n%i;
    	    ans+=(n/i)*(i-k);
    	    ans+=max(tmp-k+1,(long long)0);
	    }
	    if(k==0)ans=n*n; 
    } 
	cout<<ans<<endl;
    return 0;
}