#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

signed main()
{
    int N, K;
    string S;
    cin >> N >> S >> K;
    char c = S[K-1];
    string ans;
    REP(i, N) {
        if(S[i] != c) { ans += '*'; }
        else { ans += c; }
    }
    printf("%s\n", ans.c_str());
    return 0;
}
