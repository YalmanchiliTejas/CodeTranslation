#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef OJ
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define all(x) (x).begin(), (x).end()
#define rsort(x) sort((x).rbegin(), (x).rend())
#define sz(x) ((int)x.size())
#define fori(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n, e) for (int i = (int)(n); i >= (int)(e); --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
#define RETURN(x) do{cout << (x) << '\n'; return 0;}while(0)

const char en = '\n';
const int MOD = 0;
const int MAXN = 0;
const int INF = 1e9;

int solve() {
    int x; cin >> x;
    cout << ((x >= 30)  ? "Yes" : "No") << en;
    return 0;
} 

int main(int argc, char **argv) {
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ntest = 1;
    //cin >> ntest;
    int t = 1;
    fori(test, ntest) {
        //cout << "Case #" << t << ": ";
        solve();
        t++;
    }

    return 0;
}
