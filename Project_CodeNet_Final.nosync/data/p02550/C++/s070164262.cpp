#include <bits/stdc++.h>

using namespace std;

using ll=long long;

ll N,X,M;

ll dp[100001];
ll idx[100001];

int main() {
    cin >> N >> X >> M;
    if(N < 1000001)
    {
        ll sum = X;
        for(ll i = 1; i < N; ++i)
        {
            (X*=X)%=M;
            sum+=X;
        }
        std::cout << sum << std::endl;
        return 0;
    }
    std::fill(idx,idx+100001,-1);
    dp[0] = X;
    idx[X] = 0;
    ll loopIdx, loopSz;
    for(ll i = 1; i < N; ++i)
    {
        (X*=X)%=M;
        dp[i] = dp[i-1]+X;
        if(idx[X]!=-1)
        {
            //loop
            loopIdx = idx[X];
            loopSz = i - loopIdx;
            break;
        }
        idx[X] = i;
    }
    ll sum = loopIdx==0?0:dp[loopIdx-1];
    N-=loopIdx;
    sum += (N/loopSz)*(dp[loopSz+loopIdx-1] - (loopIdx==0?0:dp[loopIdx-1]));
    N = (N-(N/loopSz)*loopSz);
    if(N)sum += dp[loopIdx+N-1]-(loopIdx==0?0:dp[loopIdx-1]);
    std::cout << sum << std::endl;
}