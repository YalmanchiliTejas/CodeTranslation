#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll bur[55], pat[55];

ll solve(int n, ll x){
    if(x == 1) return (n == 0 ? 1 : 0);
    else if(1 < x && x <= 1 + bur[n-1]) return solve(n-1, x-1);
    else if(x == 2 + bur[n-1]) return pat[n-1] + 1;
    else if(2 + bur[n-1] < x && x <= 2 + 2*bur[n-1]) return pat[n-1] + 1 + solve(n-1, x-2-bur[n-1]);
    else if(x == 3 + 2*bur[n-1]) return pat[n-1] * 2 + 1;
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll x;
    cin >> n >> x;
    bur[0] = 1;
    pat[0] = 1;
    rep(i,50){
        bur[i+1] = 3 + bur[i] * 2;
        pat[i+1] = 1 + pat[i] * 2;
    }
    ll ans = solve(n, x);
    cout << ans << endl;
    return 0;
}