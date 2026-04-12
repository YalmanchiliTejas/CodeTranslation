#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<n; i++)
using namespace std;
typedef long long ll;


//あらかじめ50層目までのバーガーの高さ、パティの数を計算しておく
ll h[51];
ll p[51];

void calh() {
    h[0] = 1;
    for(ll i=1; i<51; i++) {
        h[i] = 2*h[i-1] + 3;
    }
}

void calp() {
    p[0] = 1;
    for(ll i=1; i<51; i++) {
        p[i] = 2*p[i-1] + 1;
    }
}

//レベルnバーガーの下からx層までに食べるパティを
//再帰関数によって求める
ll calpp(ll n, ll x) {
    if(x <= n) return 0;
    if(n == 0) return 1;
    if(x < h[n-1]+2) return calpp(n-1, x-1);
    //if(x == h[n-1]+2) return calp(n-1, h[n-1]) + 1;
    if(x >= h[n-1]+2) return p[n-1] + 1 + calpp(n-1, x-(h[n-1]+2));
}

int main() {
    ll N, X;
    cin >> N >> X;
    calh();
    calp();

    cout << calpp(N, X) << endl;
    return 0;

}