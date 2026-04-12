#include <bits/stdc++.h>
using namespace std;
//13.23
typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

// bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
//     return arg1.first > arg2.first;
// }

// template<class T> void chmin(T& a, T b) {
//     if (a > b) {
//         a = b;
//     }
// }

// template<class T> void chmax(T& a, T b) {
//     if (a < b) {
//         a = b;
//     }
// }

vector<ll> a(51);
vector<ll> p(51);

ll solve(ll n, ll x) {
    if(n==0) return 1;
    else if(x==1) return 0;
    else if(1<x&&x<=1+a.at(n-1)) return solve(n-1, x-1);
    else if(x==2+a.at(n-1)) return p.at(n-1)+1;
    else if(2+a.at(n-1)<x&&x<=2+2*a.at(n-1)) return p.at(n-1)+1+solve(n-1, x-2-a.at(n-1));
    else return 2*p.at(n-1)+1;
}

int main(void) {
    ll n, x;
    cin >> n >> x;

    a.at(0) = 1;
    p.at(0) = 1;
    for(int in=1;in<=50;in++) {
        a.at(in) = 2*a.at(in-1) + 3;
        p.at(in) = 2*p.at(in-1) + 1;
    }

    cout << solve(n, x) << endl;

    return 0;
}
