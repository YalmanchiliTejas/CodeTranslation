#include<bits/stdc++.h>
using namespace std;


int main(void){
   int N;
   cin>>N;
   long long mod=1000000007;
   vector<long long> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   vector<long long> sum(N+1);
   sum[0]=0;
   for(int i=0;i<N;i++){
      sum[i+1]=(sum[i]+A[i])%mod;
   }
   
   long long ans=0;
   for(int i=0;i<N-1;i++){
      ans+=A[i]*sum[N]%mod;
      ans-=A[i]*sum[i+1]%mod;
   }
   if(ans<0){
      cout<<ans%mod+mod<<endl;
   }else{
      cout<<ans%mod<<endl;
   }
   return 0;
}
