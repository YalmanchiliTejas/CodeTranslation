#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

vector<ll> b;
ll rec(ll n, ll x) {
    if (n == 0)
        return 1;
    ll len = (1LL << (n + 1)) - 3; //　n-1回目のバンの数 
    ll num = (1LL << (n)) - 1;     //　n-1回目のパティの数
    // xの値で場合分け
    if (x == 1)
        return 0;
    else if (x <= len + 1)
        return rec(n - 1, x - 1);
    else if (x == len + 2)
        return num + 1;
    else if (x <= (len + 1) * 2)
        return num + 1 + rec(n - 1, x - len - 2);
    else
        return num * 2 + 1;   //　ぴったり
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X;
    cin >> N >> X;
    cout << rec(N, X) << endl;
}