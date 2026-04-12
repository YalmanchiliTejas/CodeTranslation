#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;

vector<ll> A;
vector<ll> dp;

ll solve(int l, int N){
    if(N-l==3){
        return max({A[N-3], A[N-2], A[N-1]});
    }
    ll ans1 = A[l] + solve(l+2,N);
    ll ans2 = A[l+1] + max(dp[l+3],dp[l+4]);
    ll ans3 = dp[l+2];
    return max({ans1,ans2,ans3});
}

int main() {
    int N; cin >> N;
    A.resize(N,0);
    REP(i,N) cin >> A[i];

    dp.resize(N,-LINF);

    dp[N-1] = A[N-1];
    dp[N-2] = A[N-2];
    for(int i=N-1; i>=2; i--){
        if((N-1-i)%2 ==0){
            if(i>=3) dp[i-3] = max(dp[i-3], dp[i]+A[i-3]);
        }
        dp[i-2] = max(dp[i-2], dp[i]+A[i-2]);
    }
    //REP(i,N) cout << dp[i] << endl;
   

    if(N%2==0){
        cout << max(dp[0],dp[1]) << endl;
    }else{
        cout <<  solve(0, N) << endl;
    }

    return 0;
}