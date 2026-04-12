#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    llong N,A[200100],mod=1000000007,sum[200100],ans=0;
    cin >> N;
    rep(i,N) cin >> A[i];
    //累積和
    sum[N-1] = A[N-1];
    sum[N-1] %= mod;
    for(int i=N-2;i >= 0;i--){
        sum[i] = sum[i+1] + A[i];
        sum[i] %= mod;
    }
    
    for(int i=0;i<N-1;i++){
        ans += A[i]*sum[i+1];
        ans %= mod;
    }
    
    cout << ans << endl;
    
    return 0;
}