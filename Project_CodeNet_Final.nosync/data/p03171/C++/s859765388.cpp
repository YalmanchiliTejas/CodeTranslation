#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=(ll)(1e9+7);
ll run();
int main() {
#ifdef home
    freopen("i", "r", stdin);
    freopen("d", "w", stderr);
#endif
    cout.precision(15);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}
const ll inf = (1e18+5);

void max_self(int &a, int b){
    a= max(a,b);
}

void min_self(ll &a, ll b){
    a=min(a,b);
}

int a[3005];
ll dp[3005][3005];

ll f(int i, int j){
    if(j==i)
        return a[i];
    if((j-i)==1)
        return max(a[i],a[j]);
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j]=max(a[i]+min(f(i+2,j),f(i+1,j-1)), a[j] + min(f(i+1,j-1),f(i,j-2)));
}

ll run() {
    int n;
    cin>>n;
    ll sum =0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    memset(dp,-1,sizeof(dp));

    ll ans = f(1,n);
    ans=ans-(sum-ans);
    cout<<ans;
}
