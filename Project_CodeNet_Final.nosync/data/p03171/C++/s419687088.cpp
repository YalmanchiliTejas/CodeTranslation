// failed to generate code

#include <bits/stdc++.h>
using namespace std;

bool flg[3000][3001][2];

long long dp[3000][3001][2];
int N;
vector<int> a;

long long op(long long a,long long b,int f){
    if( f == 0 ) return max(a, b);
    else return min(a, b);
}
long long coef(int f){
    return f == 0 ? 1 : -1;
}

long long dfs(int l, int r,int f){
    if( flg[l][r][f] ) return dp[l][r][f];
    if( r - l == 1 ) return coef(f) * a[l];

    flg[l][r][f] = true;
    return dp[l][r][f] = op(dfs(l, r-1, f^1) + a[r-1] * coef(f), dfs(l+1, r, f^1) + a[l] * coef(f) , f);;
}
int main(){
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false);

    cin >> N;
    a.resize(N);
    for(int i = 0 ; i < N ; i++) cin >> a[i];

    cout << dfs(0, N, 0) << endl;
}
