#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, k;
string s;
long long dp[102][102][2];

long long solve(int i, int cnt, bool limiar){
    long long * ref = &dp[i][cnt][limiar];
    
    if (*ref != -1) return *ref;
    if (i == n){
        if (cnt == k) return *ref = 1;
        else return *ref = 0;
    }
    if (cnt > k) return *ref = 0;

    long long lim = (limiar ? s[i] - '0' : 9);

    if (limiar){
        if (lim == 0) *ref = solve(i+1, cnt, 1);
        else *ref = solve(i+1, cnt, 0) + (lim-1) * solve(i+1, cnt+1, 0) + solve(i+1, cnt+1, 1);
    } else{
        *ref = solve(i+1, cnt, 0) + 9LL * solve(i+1, cnt+1, 0);
    }
    //cout << "dp[" << i << "][" << _k << "][" << limiar << "] = " << ans << endl;
    return *ref;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> k;
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 1);
}