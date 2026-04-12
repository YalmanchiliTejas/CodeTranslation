#include<bits/stdc++.h>
using namespace std;
long long h[200009];
long long dp[109];

long long mod = 1e9+7;
vector< pair<long long,long long> > v[109];
long long exp(long long b){
    if(!b) return 1;
    if(b&1) return 2*exp(b-1)%mod;
    long long k = exp(b/2);
    return k*k%mod;
}
main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(long long i = 1; i <= n; i++){
        if(h[i-1] > h[i]) continue;
        long long lo = max((long long)2,h[i-1]+1), hi = h[i];
        for(long long j = i; j <= n; j++){
            if(max((long long)0,hi - max(lo,h[j]+1)+1)) v[i].push_back({j-1,max((long long)0,hi - max(lo,h[j]+1)+1)});
            hi = min(hi,h[j]);
        }
        if(max((long long)0,hi-lo+1)) v[i].push_back({n,max((long long)0,hi-lo+1)});
    }
    for(long long i = n; i >= 1; i--){
        for(long long j = i; j <= n; j++){
        long long A = 0;
            for(long long k = i; k <= j; k++){
                for(long long t= 0; t < v[k]. size(); t++){
                    long long r = v[k][t].first, N =  v[k][t].second;
                    if(r <= j) A+= N;
                }
            }
        if(j == n) dp[i] = (dp[i] + exp(A)) % mod;
        else dp[i] = (dp[i] + dp[j+1] * exp(A))% mod;
        }
    }
    cout<<  dp[1] * 2 % mod << endl;

}
