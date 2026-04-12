// Let's bring the sky down :)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3 + 5;
ll a[N];
ll dp[N][N];
bool vis[N][N];
int n;
ll solve(int l, int r){
    if(l > r)
        return 0;
    int left = n - (r - l + 1);
    left &= 1;
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    ll ans;
    if(!left){
        ans = max(a[l] + solve(l + 1, r), a[r] + solve(l, r - 1));
    }
    else{
        ans = min(-a[l] + solve(l + 1, r), -a[r] + solve(l, r - 1));
    }
    dp[l][r] = ans;
}
int main()
{
    ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1);
return 0;
}
