#include <bits/stdc++.h>
using namespace std;
#define mod (1000*1000*1000+7)
typedef long long ll;
const int N = 100001, D = 101;
ll dp[N][D],d;
int dig[N];
ll sum(int pos, int md) {
    if(pos == 1) {
        int c = 0;
        for(int i = 0; i <= dig[pos]; ++i)
            if((md+i)%d == 0) ++c;
        return c;
    }
    ll ans = 0;
    for(int i = 0; i <= dig[pos]; ++i) {
        if(i == dig[pos])
            ans = (ans + sum(pos-1,(md+i)%d))%mod;
        else {
            ans = (ans + dp[pos-1][(100*d-md-i)%d])%mod;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string k; cin>>k>>d;
    int n = k.size();
    for(int i = n; i >= 1; --i) dig[i] = k[n-i]-'0'; 
    for(int i = 0; i <= 9; ++i)
        dp[1][i%d]++;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < d; ++j)
            for(int l = 0; l <= 9; ++l) 
                dp[i+1][(j+l)%d] = (dp[i+1][(j+l)%d] + dp[i][j])%mod;
    cout<<(sum(n,0)-1+mod)%mod<<"\n";
}