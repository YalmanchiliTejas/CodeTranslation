#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

vector<ll> s(51, 0);

ll f(ll L, ll X) {
    if (L == 0) {
        if (X <= 0) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if (X <= 1) {
            return 0;
        } else if (2 <= X && X <= s[L-1]+1) {
            return f(L-1, X-1);
        } else if (X == s[L-1] + 2) {
            return f(L-1, s[L-1])+1;
        } else if (s[L-1] + 3 <= X && X <= 2 * s[L-1] + 2) {
            return f(L-1, s[L-1]) + 1 + f(L-1, X-s[L-1]-2);
        } else {
            return 2*f(L-1, s[L-1]) + 1;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X;
    cin >> N >> X;

    s[0] = 1;
    Rep (i, 50) {
        s[i+1] = 2*s[i] + 3;
    }
    // cout << s[50] << "\n";
    cout << f(N, X) << "\n";
}