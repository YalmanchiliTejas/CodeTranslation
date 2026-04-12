#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>


int main(){
    long N;
    std::cin >> N;
    long A[200000+1];
    for(long i=1; i<=N; i++){
        std::cin >> A[i];
    }
    long sum=0;
    long MOD=1000000000+7;
    for(long i=2; i<=N;i++){
        sum+=A[i];
        sum=sum%MOD;
    }
    long sum2=0;
    for(long i=1; i<=N; i++){
        long temp2=sum*A[i];
        temp2=temp2%MOD;
        sum2+=temp2;
        sum2=sum2%MOD;
        if(i!=N){
        sum=sum-A[i+1];
        sum=sum%MOD;
        if(sum<0){
            sum+=MOD;
        }
        }
    }
    std::cout << sum2 << std::endl;
    return 0;
}