#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>


long long  INF=1000000000000000000;
using namespace std;


int main(){

long long  N,K;
cin>>N>>K;

long long ans=0;
if(K==0){
    ans=N*N;
    cout<<ans<<endl;
    return 0;
}
/*
for( int i=K;i<=N;i++){
    for(int l=K+1;l<=N;l++){
        if(i>l && )

        if(i<l){
            ans+=N-l+1;
            break;  
            }     
        if(i%l>=K ){
            ans++;   
        }
    }
}
*/
for(long long  l=K+1;l<=N;l++){
        ans+=(N/l)*(l-K);
        long long  t=N%l;
        long long p=0;
        if(t>=K){
        ans+=max(p,t-K+1);
        }
}

cout<<ans<<endl;
 return 0;
}
/*
5 2

7

10 0

100

31415 9265

287927211
*/