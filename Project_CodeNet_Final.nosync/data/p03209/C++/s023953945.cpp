#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

int gcd(int a, int b){
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

// レベル n のバーガーの総レイヤー数
ll numlayer(ll n){
    return (ll)pow(2, n+2) - 3;
}

// レベル n に含まれるパティの数
ll nump(ll n){
    return (ll)pow(2, n+1) - 1;
}

ll countpaty(ll N, ll X){
    if (N == 0) {
        return (X <= 0) ? 0 : 1;
    }

    if (X <= 1 + numlayer(N-1)) {
        return countpaty(N-1, X-1);
    }else{
        return nump(N-1) + 1 + countpaty(N-1, X-2-numlayer(N-1));
    }

}


void solve(){
    ll N, X;
    cin >> N >> X;
    cout << countpaty(N, X) << endl;

    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}
