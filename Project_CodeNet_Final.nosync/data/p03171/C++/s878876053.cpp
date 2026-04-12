///17571@nith.ac.in @Ankit Verma
#include <bits/stdc++.h>
using namespace std;
#define ff          first
#define ss          second
#define pb          push_back
#define MP          make_pair
#define int         long long
#define ll          long long
#define inf         0x3f3f3f3f
#define MOD         1000000007
#define ld          long double
#define eb          emplace_back
#define pii         pair<int,int>
#define ull         unsigned long long
#define all(v)      v.begin(), v.end()
#define f(i,x,n)    for(int i=x;i<n;i++)
#define fr(i,x,n)   for(int i=x;i>=n;i--)
#define fastio      ios::sync_with_stdio(false)

#define n_l '\n'
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); } 
#define debug(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl

void IO() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const int N = 3100;
int dp[N][N];
vector <int> ar(N);
int solve(int i, int j) {
	int &ans = dp[i][j];
	if (i == j) {
		return ar[i];
	}
	if (j - i == 1) {
		return max(ar[i], ar[j]);
	}
	if (ans != -1) return ans;
	int res = 0;
	res = max(ar[i] + min(solve(i + 2, j), solve(i + 1, j - 1)), ar[j] + min(solve(i + 1, j - 1), solve(i, j - 2)));
	return ans = res;
}

int32_t main() {
    //IO();
    fastio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
    	cin >> ar[i];
    	sum += ar[i];
    }
    memset(dp, -1, sizeof dp);
    int x = solve(0, n - 1);
    int y = sum - x;
    cout << x - y << endl;
    return 0;
}
