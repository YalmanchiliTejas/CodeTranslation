#include <iostream>
#include <algorithm>
using namespace std;
long long panoj(long long N,long long X){
    long long i,pan[51],sum[51];
    pan[0]=0;sum[0]=1;
    for(i=0;i<51;i++){
        pan[i+1]=pan[i]*2+2;
        sum[i+1]=sum[i]*2+3;
    }
    if(X==sum[N]){
        return pan[N];
    }else if(X>sum[N-1]+1){
        return pan[N-1]+1+panoj(N-1,X-sum[N-1]-2);
    }else if(X>0){
        return 1+panoj(N-1,X-1);
    }else{
        return 0;
    }
}
int main(void){
    long long N,X;
    cin>>N>>X;
    cout<<X-panoj(N,X)<<endl;
}