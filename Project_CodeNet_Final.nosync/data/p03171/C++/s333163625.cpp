#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3001;
ll dp[N][N][2], a[N];
ll calc(int s, int e, int t) {
    if(dp[s][e][t]) return dp[s][e][t];
    if(s == e) {
        dp[s][e][0] = a[s]; 
        dp[s][e][1] = -a[s];
        return dp[s][e][t];
    }
    if(s > e)
        return 0;
    if(t) 
        dp[s][e][t] = min(-a[s]+calc(s+1,e,t^1),-a[e]+calc(s,e-1,t^1));
    else 
        dp[s][e][t] = max(a[s]+calc(s+1,e,t^1),a[e]+calc(s,e-1,t^1));
    return dp[s][e][t];
}
int main() {
    int n; cin>>n; 
    for(int i = 1; i <= n; ++i) cin>>a[i];
    cout<<calc(1,n,0)<<"\n";
}