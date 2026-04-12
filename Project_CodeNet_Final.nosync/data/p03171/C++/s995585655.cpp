#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
ll n, a[3009], dp[3009][3009];
ll get(int l, int r) {
    if(l > r)
        return 0ll;
    return dp[l][r];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int len=1;len<=n;len++) {
        for(int l=1;l<=n-len+1;l++) {
            int r = l + len - 1;
            dp[l][r] = max(a[l] - get(l + 1, r), a[r] - get(l, r - 1));
        }
    }
    cout<<dp[1][n];
}
