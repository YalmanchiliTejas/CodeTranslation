#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;

const ll INF = 5e15;
const ll MOD = 1e9 + 7;

ll N;
vector<ll> A;
vector<vector<ll>> memo(3000 + 10, vector<ll>(3000 + 10, INF));

ll solve(ll f, ll b){
    if(f + b == N) return memo[f][b] = 0;
    if(memo[f][b] != INF) return memo[f][b];
    if((f + b) % 2 == 0){
        ll v1 = solve(f + 1, b) + A[f];
        ll v2 = solve(f, b + 1) + A[N - 1 - b];
        return memo[f][b] = max(v1, v2);
    }else{
        ll v1 = solve(f + 1, b) - A[f];
        ll v2 = solve(f, b + 1) - A[N - 1 - b];
        return memo[f][b] = min(v1, v2);
    }
}

int main(){
    cin >> N;
    A.resize(N);
    for(ll &a : A) cin >> a;
    solve(0, 0);
    cout << memo[0][0] << endl;
    return 0;
}
