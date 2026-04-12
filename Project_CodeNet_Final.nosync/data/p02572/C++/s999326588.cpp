#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
const long double PI = (acos(-1));
const long long MOD = 1000000007;

static const int  MAX_INT = std::numeric_limits<int>::max();
static const long MAX_LONG = std::numeric_limits<long>::max();
static const ll   MAX_LL = std::numeric_limits<long long>::max();

#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)

///////////////////////////////////////////////////
// ------------------- utils ------------------- //
///////////////////////////////////////////////////
// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

///////////////////////////////////////////////////
// ------------------- main -------------------- //
///////////////////////////////////////////////////
void Main() {
    ll N; cin >> N;
    vector<ll> A(N, 0), Cum(N,0);
    rep(i, N) cin >> A[i];

    Cum[0] = A[0];
    for (int i = 1; i < N; ++i) Cum[i] = (Cum[i - 1] + A[i]) % MOD;
    
    ll sum = 0;
    rep(i, N - 1) {
        ll thisSum = (Cum[N - 1] - Cum[i]) % MOD;
        if (thisSum < 0) thisSum += MOD;
        sum += (A[i] * thisSum);
        sum %= MOD;
    }
    cout << sum << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15);
    Main();

    double tmp;
    cin >> tmp;

    return 0;
}
