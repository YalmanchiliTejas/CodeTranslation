#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, v[3005];
ll dp[3005][3005][5];

ll solve(ll esq, ll dir, ll flag){
    if(esq == dir) return + (flag == 0 ? 1 : -1) * v[esq];
    if(dp[esq][dir][flag] != -1) return dp[esq][dir][flag];
    ll r1 = solve(esq+1, dir, !flag) + (flag == 0 ? 1 : -1) * v[esq];
    ll r2 = solve(esq, dir-1, !flag) + (flag == 0 ? 1 : -1) * v[dir];
    if(flag == 0) return dp[esq][dir][flag] = max(r1,r2);
    else return dp[esq][dir][flag] = min(r1,r2);
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; i++)
        cin >> v[i], sum += v[i];
    cout << solve(0, n-1, 0) << endl;
	return 0;
}
