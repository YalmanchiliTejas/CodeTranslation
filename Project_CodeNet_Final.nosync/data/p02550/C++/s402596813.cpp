#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<vi> vvi;
const int MOD = 1e9 + 7;

#define fastIO \
ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mp make_pair 

#ifdef DIV_DEBUG
#define cerr(...) __cerr(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __cerr(const char *name, Arg1 &&arg1) {
    cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __cerr(const char *names, Arg1 &&arg1, Args&&... args) {
    const char *sep = strchr(names + 1, ',');
    cerr.write(names, sep - names) << " = " << arg1 << " |";
    __cerr(sep + 1, args...);
}
#else
#define cerr(...) 
#endif


int main() {
    fastIO;
    ll N, X, M;
    cin >> N >> X >> M;

    vi psum;
    vi found(M, -1);
    ll A = X;
    while (found[A] == -1) {
        found[A] = int(psum.size());
        psum.pb(A);
        A = (A * A) % M;
    }

    int sz = psum.size();
    if (N < sz) {
        for (int i = 1; i < sz; i++)    psum[i] += psum[i - 1];
        cout << psum[N - 1] << endl;
        return 0;
    }
    
    for (int i = 1; i < found[A]; i++)    psum[i] += psum[i - 1];
    for (int i = found[A] + 1; i < sz; i++) psum[i] += psum[i - 1];
    ll ans = found[A] > 0 ? psum[found[A] - 1] : 0;
    ll cycles = (N - found[A]) / (sz - found[A]), rem = (N - found[A]) % (sz - found[A]);
    ans += cycles * psum[sz - 1] + (rem > 0 ? psum[found[A] + rem - 1] : 0);
    cout << ans << endl;
    return 0;
}   