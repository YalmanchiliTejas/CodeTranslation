#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

vector<ll> m(51, 0), p(51, 0);
ll dfs(ll x, int l){
    if(l == 0)return 1;
    if(x == m[l])return p[l];
    else if(x > (2 + m[l - 1]))return p[l-1]+1+dfs(x-m[l-1]-2, l-1);
    else if(x == (2 + m[l - 1]))return p[l-1]+1;
    else if(x > 1)return dfs(x-1, l-1);
    else return 0;
}

int main() {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    m[0] = 1;
    p[0] = 1;
    rep(i, 50){
        m[i + 1] = m[i] * 2 + 3;
        p[i + 1] = p[i] * 2 + 1;
    }
    ll ans = dfs(x, n);
    cout << ans << endl;
}