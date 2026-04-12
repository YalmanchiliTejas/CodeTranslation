#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

ll solve(int n, ll x, vector<ll> &a, vector<ll> &p){
    if(n == 0) return 1; // ここは例外が必要　他だと0を返してしまうので

    if(x == 1) return 0;
    else if(x <= 1+a[n-1]) return solve(n-1, x-1, a, p);
    else if(x == a[n-1]+2) return p[n-1]+1;
    else if(x <= 2+2*a[n-1]) return p[n-1]+1+solve(n-1, x-2-a[n-1], a, p);
    else if(x == 3+2*a[n-1]) return p[n];

    return 0;
}

int main(){
    int N; cin >> N;
    ll X; cin >> X;
    vector<ll> a(N+1, 1LL), p(N+1, 1LL);
    for(int i=1; i<=N; i++){
        a[i] = 2*a[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }

    cout << solve(N, X, a, p) << endl;
}