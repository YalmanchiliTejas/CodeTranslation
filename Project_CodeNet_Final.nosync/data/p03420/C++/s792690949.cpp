#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K; scanf("%d%d",&N,&K);
    if(K==0) return !printf("%lld\n", 1LL*N*N);
    long long ans = 0;
    for(int b=K+1;b<=N;b++){
        // a%b>=K
        int x = (N+1)/b, y = (N+1)%b;
        ans += 1LL*x*(b-K);
        if(y>=K+1) ans += y-K;
    }
    printf("%lld\n",ans);
}
