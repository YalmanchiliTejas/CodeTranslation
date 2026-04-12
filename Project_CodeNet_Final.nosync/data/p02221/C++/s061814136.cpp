#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tp3 = tuple<int, int, int>;
using Mat = vector<vector<ll>>;
constexpr int INF = 1 << 28;
constexpr ll INFL = 1ll << 60;
constexpr int dh[4] = { 0,1,0,-1 };
constexpr int dw[4] = { -1,0,1,0 };
bool isin(const int H, const int W, const int h, const int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
template<typename T>
T minch(T& l, T& r) {
    return l = min(l, r);
}
template<typename T>
T maxch(T& l, T& r) {
    return l = max(l, r);
}
template<typename T>
void output(const T& val) {
    cout << val << endl;
}
template<typename T>
void output(const vector<T>& vec, const bool newline = false) {
    for (const T& val : vec)cout << val << (newline ? '\n' : ' '); cout << endl;
}
template<typename T>
void output(const vector<vector<T>>& mat) {
    for (const auto& row : mat)output(row);
}
// ============ template finished ============


vector<int> doubles;
int mpow(int size) {
    int res = 1;
    rep(i, size)res *= 2;
    return res;
}

int buttle(
    const string& s,
    const vector<int>& P,
    int l,
    int r
) {
    const int M = P.size();
    if (P[l] > P[r])swap(l, r);
    return s[P[r] - P[l] - 1] == '0' ? l : r;
}

int dfs(
    const string& s,
    const vector<int>& P,
    vector<vector<int>>& memo,
    int L,
    int size
) {
    const int M = P.size();
    if (memo[L][size] != -1)return memo[L][size];
    if (size == 1) return memo[L][size] = buttle(s, P, L, (L + 1) % M);

    int nsize = size - 1;
    int mid = (L + doubles[nsize]) % M;
    int winl = dfs(s, P, memo, L, nsize);
    int winr = dfs(s, P, memo, mid, nsize);
    return memo[L][size] = buttle(s, P, winl, winr);
}

int main()
{
    // input
    int N;
    string s;
    cin >> N >> s;
    const int M = mpow(N);
    vector<int> P(M);
    rep(i, M) cin >> P[i];

    // process
    rep(i, 25)doubles.push_back(mpow(i));
    vector<vector<int>> memo(M, vector<int>(N + 1, -1));
    rep(i, M) {
        cout << P[dfs(s, P, memo, i, N)] << endl;
    }

    return 0;
}

