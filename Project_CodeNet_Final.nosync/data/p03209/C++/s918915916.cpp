#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

ll layer[100], patty[100];

ll solve(ll N, ll X);

int main(void){
    ll N, X;
    cin >> N >> X;
    layer[0] = 1ll; patty[0] = 1ll;
    for(int i = 1; i <= N; i++){
        layer[i] = layer[i-1]*2 + 3;
        patty[i] = patty[i-1]*2 + 1;
    }
    
    cout << solve(N, X) << endl;

    return 0;
}

ll solve(ll N, ll X){
    if(N == 0) return 1;
    else if(X == 1) return 0;
    else if(X == layer[N]/2 + 1) return patty[N-1] + 1;
    else if(X <= layer[N]/2) return solve(N-1, X-1);
    else return patty[N-1] + 1 + solve(N-1, X-2-layer[N-1]);
}