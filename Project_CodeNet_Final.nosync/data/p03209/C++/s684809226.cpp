
#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e18+1;


//パティの枚数 P[i]

//P[0] = 1
//P[i+1] = 2 * P[i] + 1

//P[n] = 2 ^ (n+1) - 1


//層の個数 S[i]

//S[0] = 1
//S[i+1] = 2 * S[i] + 3

//S[n] = 2 ^ (n+2) - 3


//レベルNバーガーを作るので
//層数は2^(n+2) - 3
//このX層まで食べる
//
//バーガーのデカいほうから、貪欲に数えていく
//カウントするたびにそのパティの数を加算

ll f(ll N, ll X, vector<ll> &S, vector<ll> &P) {
    if (N == 0) {
        if (X <= 0) return 0;
        return 1;
    } else if (X <= 1 + S[N-1]) {
        return f(N-1,X-1,S,P);
    }
    return P[N-1] + 1 + f(N-1,X-2-S[N-1],S,P);
}

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> P(N+1,0),S(N+1,0);
    P[0] = S[0] = 1;
    for (int i = 1; i <= N; i++) {
        P[i] = 2 * P[i-1] + 1;
        S[i] = 2 * S[i-1] + 3;
    } 
    

    cout << f(N,X,S,P) << endl;

}