#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll W[55];
ll P[55];

ll patee(ll l, ll n){
    ll whole = W[l];
    ll pate = P[l];
    if(l == 0){
        return 1;
    }
    if(n == 1){
        return 0;
    }
    if(n > 1 && n < (whole/2) + 1){
        return patee(l-1, n-1);
    }
    if(n == (whole/2) + 1){
        return P[l-1]+1;
    }
    if(n < whole){
        return P[l-1]+1 + patee(l-1, n-((whole/2)+1));
    }

    return pate;
}

int main() {
    ll N, X; cin >> N >> X;
    W[0] = 1;
    P[0] = 1;
    for (int i = 1; i <= N; i++){
        W[i] = W[i-1]*2 + 3;
        P[i] = P[i-1]*2 + 1;
    }
    cout << patee(N, X) << endl;

    return 0;
}