#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 +7;
string s; 
int dp[103][4][2];
ll n; int k;
int solve(int pos, int cnt, bool f) {
    if(cnt > k) return 0;
    if(dp[pos][cnt][f] != -1)   return dp[pos][cnt][f];
    if(pos == n) {
        if(cnt == k)    return 1;
        else    dp[pos][cnt][f] = 0;
        return 0;
    }

    dp[pos][cnt][f] = 0;
    int lim;
    if(f == 0)  lim = s[pos] - '0';
    else    lim = 9;

    for(int dig = 0; dig <= lim; dig++) {
        int ncnt = cnt + (dig!=0);
        int nf = (f==1 || dig<lim);
        dp[pos][cnt][f] = (dp[pos][cnt][f] + solve(pos+1, ncnt, nf)) % mod;
    }
    return dp[pos][cnt][f];
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s; n = s.length(); cin>>k;
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0, 0);
    return 0;
}