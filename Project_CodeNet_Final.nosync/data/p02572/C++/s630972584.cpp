#include <bits/stdc++.h>
using namespace std;

int main() {
   
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        
        long long sum[n];
        sum[0]=a[0];
         int mod=(int)1e9+7;
        for(int i=1;i<n;i++){
            sum[i]=(a[i]+sum[i-1]+mod)%mod;
        }
       
        long long tsum=sum[n-1];
        long long totalsum=0;
        for(int i=0;i<n;i++){
            totalsum=(totalsum+(1ll*a[i]*(tsum-sum[i])+mod)%mod+mod)%mod;
        }
        cout<<(totalsum+mod)%mod<<endl;
    
	//code
	return 0;
}
