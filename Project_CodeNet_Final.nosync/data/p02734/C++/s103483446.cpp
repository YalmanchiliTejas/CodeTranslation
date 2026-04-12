#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e3+10,mod=998244353;
ll dp[N][N];
ll a[N];
int32_t main(){
    sync;
    ll n,s;
    cin >> n >> s;
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<N;j++){
            dp[i][j]=dp[i-1][j];
            if (j-a[i]>=0) dp[i][j]+=dp[i-1][j-a[i]];
            if (j==0) dp[i][j]++;
            dp[i][j]%=mod;

        }
    }
    ll ans=0;
    for (int i=1;i<=n;i++) ans+=dp[i][s];
    cout << ans%mod << endl;
}
