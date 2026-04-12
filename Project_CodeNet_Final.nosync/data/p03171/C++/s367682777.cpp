#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int n,k;
int a[3003];
ll dp[3003][3003];
main() {
    ios::sync_with_stdio(0);
    cin >> n;
    int c = (n%2);
    ll s  =0;
    for (int i = 0; i < n;i++)
        cin >> a[i],s+=a[i];

    for (int r = 0; r < n ; r++)
    for (int l = r; l >= 0; l--) {
        int d = (r-l+1)%2;
        if (r == l) {if (d==c)dp[l][r] = a[l];}
        else {
            if (d == c)
                dp[l][r] = max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
            else dp[l][r] = min(dp[l+1][r],dp[l][r-1]);
        }
    }
    cout << 2*dp[0][n-1]-s;
}
