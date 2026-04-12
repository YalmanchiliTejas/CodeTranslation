#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    long long N,X,i,pan[51],sum[51];
    cin>>N>>X;
    long long x=X;
    pan[0]=0;sum[0]=1;
    for(i=0;i<51;i++){
        pan[i+1]=pan[i]*2+2;
        sum[i+1]=sum[i]*2+3;
    }
    long long pansum=0;
    for(i=N;i>0;i--){
        if(X==sum[i]){
            pansum+=pan[i];
            break;
        }
        if(X>sum[i-1]+1){
            pansum+=pan[i-1]+1;
            X-=sum[i-1]+2;
        }else{
            if(X>0){
                pansum++;
                X--;
            }
        }
    }
    cout<<x-pansum<<endl;
}
