#include <iostream>



using namespace std;

long long ans(int L,long long X){
    long long size = 1LL << (L+2);
    size-=3;
    if(X==0)return 0;
    if(L==0)return 1;
    if(X <= (1LL << (L+1)) -3 +1)return ans(L-1,X-1);
    return (1LL << L) + ans( L-1,X- ((1LL << (L+1)) -3 +2));
}


int main(void){
    int N;
    long long X;
    scanf("%d%lld",&N,&X);
    printf("%lld",ans(N,X));
    
    
    return 0;
}