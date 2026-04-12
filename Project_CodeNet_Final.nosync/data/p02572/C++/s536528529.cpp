#include <bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long

int tc = 1, n;
ll a[mx], pre[mx], ans[mx], sum;
const ll mod  = 1e9+7;

void solve(int kk)
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        pre[i] = (pre[i-1]%mod + a[i]%mod)%mod;
        if(pre[i]<0)
            pre[i]+=mod;
    }
    for(int i=1; i<n; i++){
        ll sub = (pre[n]%mod - pre[i]%mod)%mod;
        if(sub<0)
            sub+=mod;
        ans[i] = (a[i]%mod * sub%mod)%mod;
        if(ans[i]<0)
            ans[i]+=mod;
    }

    for(int i=1; i<n; i++){
        sum = (sum%mod + ans[i]%mod)%mod;
        if(sum<0)
            sum+=mod;
    }
    cout << sum << "\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
    freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int kk = 0;
    //cin >> tc;
    //scanf("%d", &tc);
    while (++kk <= tc)
        solve(kk);

    return 0;
}