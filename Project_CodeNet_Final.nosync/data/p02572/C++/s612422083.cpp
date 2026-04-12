#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;
typedef long long ll;

namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<1024>>;

#define INCANT cin.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define out(a) cout << a << endl
#define PRINT(V) for (auto v : (V)) cout << v << " "

const int MOD = 1000000007;
const double PI = acos(-1.0);

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> Asum(N);
    rep(i, N) cin >> A[i];
    ll sum=0;
    for(int i=N-1; i>=1; i--){
        sum = (sum + A[i]) % MOD;
        Asum[i] = sum;
    }
    ll ans=0;
    rep(i, N-1){
        ans = (ans + (A[i]*Asum[i+1])%MOD) % MOD;
    }
    out(ans);
}
int main() {
    INCANT;
    solve();
    return 0;
}


