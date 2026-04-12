#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll large[55], ps[55];

ll solve(ll now, int l){
    if(l == -1) return 1;
    if(now == 1) return 0;
    else if(now <= 1 + large[l]) return solve(now-1, l-1);
    else if(now == 2 + large[l]) return ps[l] + 1;
    else if(now <= 2 + 2*large[l]) return ps[l] + 1 + solve(now-large[l]-2, l-1);
    else return 2*ps[l] + 1;
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    
    large[0] = 1;
    ps[0] = 1;
    rep(i,n){
        large[i+1] = 2*large[i] + 3;
        ps[i+1] = 2*ps[i] + 1;
    }

    ll ans = solve(x, n-1);
    cout << ans << endl;
}
