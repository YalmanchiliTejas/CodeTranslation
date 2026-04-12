#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int N;
ll X;

ll func(ll N, ll X, vector<ll> dpp, vector<ll> f){
    if(N == 0){
        return 1;
    }
    if(X == 1)  return 0;
    if(X <= 1 + f[N-1]){
        return func(N-1, X-1, dpp, f);
    } else if(X == 2 + f[N-1]){
        return 1 + func(N-1, X-2, dpp, f);
    } else {
        return dpp[N-1] + 1 + func(N-1, X-2-f[N-1], dpp, f);
    }
}

int main(){
    cin >> N >> X;

    vector<ll> dpp(N+1);
    vector<ll> f(N+1);
    dpp[0] = 1;
    f[0] = 1;
    for(int i=0;i<N;i++){
        dpp[i+1] = dpp[i] * 2 + 1;
        f[i+1] = f[i] * 2 + 3;
    }

    ll ans = func(N, X, dpp, f);

    cout << ans << endl;
}