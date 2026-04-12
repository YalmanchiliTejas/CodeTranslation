#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;

int mod = 1000000007;

ll burger[51];
ll patty[51];

ll solve(int N, ll X){
    //レベルNバーガーの下からX層を食べる
    if(X == 0) return 0;
    else if(N == 0) return 1;
    else{
        ll eval = burger[N]/2;
        if(X <= eval) return solve(N-1, X-1);
        else return (patty[N-1] + 1) + solve(N-1, X - (eval+1));
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; ll X; cin >> N >> X;
    //レベルNバーガーに含まれるパティの数patty[N];
    burger[0] = patty[0] = 1;
    for(int i = 1; i <= N; i++){
        burger[i] = burger[i-1]*2 + 3;
        patty[i] = patty[i-1]*2 + 1;
    }
    cout << solve(N, X) << endl;
    return 0;
}