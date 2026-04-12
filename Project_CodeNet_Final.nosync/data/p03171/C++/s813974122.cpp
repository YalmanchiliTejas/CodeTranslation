#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<ll>> dp(3005, vector<ll>(3005));

    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r){
                dp[l][r]=a[l];
            }else{
                dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}

int main()
{
    // int n;
    // cin>>n;

    // while(n--)
    solve();

    return 0;
}