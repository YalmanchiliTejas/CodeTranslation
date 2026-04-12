#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main()
{
    int N;
    cin >> N;

    ll sum = 0;
    ll res = 0;
    rep(i, 0, N) {
        ll A;
        cin >> A;
        res += (A * sum) % MOD;
        res %= MOD;
        sum = (sum + A) %MOD;
    }
    cout << res << endl;
    return 0;
}
