#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "{ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "}";

    return os;
}

ll pow_mod(ll a, ll p) {
    ll res = 1;
    while(p) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }

    return res;
}


ll mod_inv(ll a, ll m) {
    ll b = m, u = 0, v = 1;
    while(a) {
        ll t = b / a;
        swap(b -= t * a, a);
        swap(u -= t * v, v);
    }

    return (u % m + m) % m;
}

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}


#ifdef LOCAL
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string N; int K;
    cin >> N >> K;

    int MD = N.size();
    ll dp[MD+1][2][K+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1; // digit, smaller, k

    REP(i, MD) {
        int d = N[i] - '0';

        REP(k, K+1) {
            // can select other than 0 for this digit.
            if (k < K) {
                // smaller -> smaller
                dp[i+1][1][k+1] += dp[i][1][k] * 9;

                if(d > 0){
                    // exact -> smaller (select smaller number than d except 0.)
                    dp[i+1][1][k+1] += dp[i][0][k] * (d - 1);

                    // exact -> exact
                    dp[i+1][0][k+1] += dp[i][0][k];
                }
            }

            // select 0 for this digit.
            dp[i+1][1][k] += dp[i][1][k];
            if (d == 0) dp[i+1][0][k] += dp[i][0][k];
            else dp[i+1][1][k] += dp[i][0][k];

        }
    }

    cout << fixed << setprecision(20);
    cout << dp[MD][0][K] + dp[MD][1][K] << endl;

}
