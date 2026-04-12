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
#include <cassert>
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
#define FIR first
#define SEC second
#define PB push_back
#define SZ(x) ((int)x.size())

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

void solveSingleCase(int caseNo)
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    lint ret = 1LL << 55;
    FOR(c, 0, 200010) {
        int x = c / 2, y = c / 2;
        lint cost = c * 1LL * C;
        if (X > x)
            cost += (X - x) * 1LL * A;
        if (Y > y)
            cost += (Y - y) * 1LL * B;
        ret = min(ret, cost);
    }

    cout << ret << endl;
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int T = 1;
    // cin >> T;
    FOR(tcase, 1, T + 1) {
        solveSingleCase(tcase);
    }
    return 0;
};
