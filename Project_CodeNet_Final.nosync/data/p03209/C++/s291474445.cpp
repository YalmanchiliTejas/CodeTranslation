#include<iostream>
#include<algorithm>
using namespace std;
long long N,X;
long long dp[55],sum=0;
long long len[55];
int main(){
    int a[7]={0,0,1,2,3,3,3};
    dp[1]=3;len[1]=5;
    for(int i=2;i<=50;i++)
        dp[i]=dp[i-1]*2+1;
    for(int i=2;i<=50;i++)
        len[i]=len[i-1]*2+3;
    scanf("%lld %lld",&N,&X);
    while(1){
        if(N==1||X==0)
            break;
        long long temp=len[N]/2;
        if(X*2>len[N]){
            bool f=0;
            if(X==len[N])
                f=1;
            sum+=dp[N-1]+1;
            X-=len[N]/2+1;
            X-=f;
        }
        else
            X--;
        N--;

    }
    if(N==1){
        sum+=a[X];
    }
    printf("%lld\n",sum);


}
