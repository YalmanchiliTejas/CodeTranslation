#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;



int main() {
    ll n; cin >> n;
    ll x, m; cin >> x >> m;
    vector<ll> A(100010), sum(100010);
    A[0] = x;
    sum[0] = x;
    map<ll, int> ch;
    ch[x] = 0;
    int i = 1;
    while(1) {
        A[i] = (A[i-1] * A[i-1]) % m;
        sum[i] = sum[i-1] + A[i];
        if(ch.find(A[i]) != ch.end()) break;
        ch[A[i]] = i;
        i++;
    }
    int s = ch[A[i]]; int t = i;
    int c = t - s;
    ll res = 0;
    n -= s;
    res += (n/c) * (sum[t] - sum[s]);
    if(s+(n%c)-1 >= 0) res += sum[s+(n%c)-1];
    cout << res << endl;
    return 0;
}
