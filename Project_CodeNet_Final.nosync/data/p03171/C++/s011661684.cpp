// 26/01/20 // 12:19 PM //

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

const int MAXN = (int)(3e3) + 10;

int n, a[MAXN];
int memo[MAXN][MAXN];

int solve(int l, int r){
    if(memo[l][r]!=-1) return memo[l][r];

    if(l>r) return memo[l][r] = 0;
    if(((r-l+1)&1)==(n&1))
        return memo[l][r] = max(a[l] + solve(l+1, r), a[r] + solve(l, r-1));
    else
        return memo[l][r] = min(solve(l+1, r) -a[l], solve(l, r-1) -a[r]);
}


void solve2(){
    for(int l=n; l>=1; l--){
        for(int r=l; r<=n; r++){
            if(((r-l+1)&1)==(n&1)) // taro
                memo[l][r] = max(a[l] + memo[l+1][r], a[r] + memo[l][r-1]);
            else
                memo[l][r] = min(memo[l+1][r] - a[l], memo[l][r-1] - a[r]);
        }
    }
}

int32_t main(){
    fastio;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];

    solve2();

    cout << memo[1][n] << endl;

    return 0;
}
