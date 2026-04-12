#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >
#define endl '\n'

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

template<class U, class V>
istream& operator >>(istream& in, pair<U, V>& pr) {
    return in >> pr.first >> pr.second;
}

template<class U, class V>
ostream& operator <<(ostream& out, pair<U, V>& p) {
    return out << p.first << " " << p.second;
}

template<class T>
ostream& operator <<(ostream& out, vector<T> vec) {
    for (T& e : vec)
        out << e << " ";
    return out << endl;
}

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

const int MAXN = 3005, MOD = 998244353;
VEC(int) A;
int dp[MAXN][MAXN];

int F(int i, int s)
{
    // indices >= i, sum exactly s.
    const int N = A.size();
    if (s == 0)
        return 1;
    if (i == N)
        return 0;

    int& ans = dp[i][s];
    if (ans >= 0)
        return ans;
    ans = F(i + 1, s);
    if (A[i] == s) {
        ans += (N - i);
        ans %= MOD;
    } else if (s > A[i]){
        ans += F(i + 1, s - A[i]);
        ans %= MOD;
    }

    return ans;
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, S;
    cin >> N >> S;
    A.resize(N);
    READVEC(A);
    memset(dp, -1, sizeof dp);

    int ret = 0;
    FOR(i, 0, N) {
        if (A[i] > S) {
            continue;
        }

        if (A[i] == S) {
            ret += (i + 1) * 1LL * (N - i) % MOD;
            ret %= MOD;
            continue;
        }

        ret += (i + 1) * 1LL * F(i + 1, S - A[i]) % MOD;
        ret %= MOD;
    }

    cout << ret << endl;
    return 0;
};