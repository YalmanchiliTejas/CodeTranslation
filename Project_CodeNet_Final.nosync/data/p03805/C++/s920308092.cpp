#include "bits/stdc++.h"
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a),i##_len=(b);i<i##_len;++i)
#define BUGAVOID(x) x
#define rep(...) BUGAVOID(_overload3(__VA_ARGS__,repi,_rep,_rep)(__VA_ARGS__))
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(),(c).end()
#define m0(a) memset(a,0,sizeof(a))
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end());
#define mp make_pair
#define write(x) cout<<(x)<<endl
#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; }return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; }return 0; }
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
struct aaa { aaa() { cin.tie(0); ios::sync_with_stdio(0); }; }aaaa;

int N, M;
bool ab[10][10];
int cond;
ll ans = 0;

ll rec(int cur, int pass) {
    if (pass == cond) return 1;
    ll cnt = 0;
    rep(i, 1, N + 1) {
        if (ab[cur][i] == 0) continue;
        if ((pass >> (i - 1)) % 2) continue;
        cnt += rec(i, pass | (1 << (i - 1)));
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        ab[a][b] = ab[b][a] = true;
    }
    cond = 0xFFFFFFFF >> (32 - N);
    ans = rec(1, 1);
    write(ans);
}