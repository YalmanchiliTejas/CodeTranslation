#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 998244353;

ll N, S, ans=0, tmp=0;
vector<ll> A;
vector<vector<ll>> DP;

signed main(){
    cin >> N >> S;
    DP.resize(N+1);
    for(int i=0;i<N+1;i++) {
        DP[i].resize(S+1,0);
        DP[i][0] = 1;
    }
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<=S;j++) {
            DP[i+1][j] += DP[i][j];
            if(j>=A[i]) DP[i+1][j] += DP[i][j-A[i]];
            DP[i+1][j] %= MOD;
        }
        ans += DP[i+1][S];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}