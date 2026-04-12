#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define FAST ;
#else
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#endif
#define _ <<' '<<
#define Fr(i, s, e) for(auto i = s; i < e; ++i)
#define Ft first
#define Sd second
using ll = long long;
using pii = pair<int, int>;
constexpr ll MAX = 1e6+5;
constexpr ll INF = 2134567890;
constexpr ll MOD = 998244353;

ll fpow(ll b, ll a, ll MOD = MOD) {
    b %= MOD;
    ll r = 1;
    for(; a; b=b*b%MOD, a>>=1)
        a&1 && (r = r*b%MOD);
    return r;
}

signed main() {
    FAST;

    string N;
    int K;
    cin >> N >> K;
    const auto FC = [](int N, int M) {
        if (N < 0 || N > M) return 0ll;
        //assert(0 <= N && N <= M);
        ll rt = fpow(9, N);
        N = min(N, M-N);
        Fr(i, 0, N) rt = rt*(M-i)/(i+1);
        return rt;
    };
    function<ll(string, int)> solve;
    solve = [&](string N, int K) {
        if (N.empty() || K == 0) return 0ll;
        //cerr _ N[0]-'0'-1 _ N.size() _ K _ FC(K-1,N.size()-1) _ FC(K,N.size()-1) _ endl;
        int sz = N.size();
        int j = 1; while (j < sz && N[j] == '0') j++;
        return solve(N.substr(j), K-1) + (N[0]-'1')*FC(K-1,sz-1) + FC(K,sz-1);
    };
    int cnt = 0;
    for(char c: N) cnt += c != '0';
    cout << solve(N, K) + (cnt >= K) << endl;

}
