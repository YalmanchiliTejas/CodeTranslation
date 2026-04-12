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

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N;
    cin >> N;
    VEC(lint) A(N);
    READVEC(A);

    const lint _infinity = 1LL << 50;

    VEC(lint) Sums(N + 1, 0);
    FORD(i, N - 1, -1) {
        Sums[i] = A[i];
        if (i + 2 < N)
            Sums[i] += Sums[i + 2];
    }

    VEC(lint) dp(N + 1, -_infinity);
    dp[N] = 0;
    FORD(i, N - 1, -1) {
        int r = N - i;
        if (r % 2 == 0) {
            dp[i] = A[i] + dp[i + 2];
            dp[i] = max(dp[i], Sums[i + 1]);
        } else {
            if (i == N - 1) {
                dp[i] = 0;
                continue;
            }

            dp[i] = Sums[i + 2];
            dp[i] = max(dp[i], A[i] + dp[i + 2]);
            dp[i] = max(dp[i], dp[i + 1]);
        }
    }

    cout << dp[0] << endl;
    return 0;
};