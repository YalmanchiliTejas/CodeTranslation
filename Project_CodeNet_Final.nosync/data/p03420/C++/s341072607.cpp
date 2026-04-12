#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll N,K;
    scanf("%lld%lld",&N,&K);
    ll ans = 0;
    for(ll b = K+1; b <= N; b++){
        //a=K,K+1,...,b-1,b+K,b+K+1,...,2*b-1,...(<=N)
        ans += (b-K) * (N/b);
        ll temp = N%b;
        if(temp >= K) ans += temp - K + 1;
    }
    if(K == 0) ans = N * N;
    printf("%lld",ans);
}