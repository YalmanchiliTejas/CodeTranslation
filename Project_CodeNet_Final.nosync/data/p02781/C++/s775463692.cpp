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

string N;
lint dp[128][4][2];

lint F(int i, int k, int l)
{
    if (i == N.size())
        return k == 0;

    lint& ans = dp[i][k][l];
    if (ans >= 0)
        return ans;

    ans = 0;
    FOR(d, 0, 10) {
        if (l == 0 && d > N[i] - '0')
            continue;
        if (d > 0 && k == 0)
            continue;
        ans += F(i + 1, k - (d != 0), l | (d < N[i] - '0'));
    }

    return ans;
};

int main(int argc, char **argv)
{
    io_init();

    int K;
    cin >> N >> K;
    memset(dp, -1, sizeof dp);
    cout << F(0, K, 0) << endl;
    return 0;
};