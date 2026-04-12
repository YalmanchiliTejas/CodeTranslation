#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
using namespace std;
using ll = long long;

constexpr int LEN = 3005;
ll dp[LEN][LEN];
bool check[LEN][LEN];

ll calc_p(int l, int r, ll a[]){
    if(check[l][r]) return dp[l][r];
    check[l][r] = true;
    if(l == r) return dp[l][r] = a[l];
    return dp[l][r] = max<ll>(a[l] - calc_p(l+1, r, a), a[r] - calc_p(l, r-1, a));
}

int main(){
    memset(dp, 0, sizeof(dp));
    memset(check, 0, sizeof(check));
    int n; cin >> n;
    ll a[n]; rep(i, n) cin >> a[i];

    cout << calc_p(0, n-1, a) << endl;

    return 0;
}