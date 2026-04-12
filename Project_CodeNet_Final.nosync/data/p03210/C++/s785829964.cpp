#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define ll long long int
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOREACH(x, a) for (auto &(x) : (a))
#define ALL(a) (a).begin(), (a).end()
#define OUT(x) out << (x) << endl;
#define M0(x) memset(x, 0, sizeof(x))
#define MINF(x) memset(x, 0x3f, sizeof(x))
#define MMINUS(a) memset(a, 0xff, sizeof(a))
#define ten(n) ((int)1e##n)

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double EPS = 1.0 / LINF;
const char ENDL = '\n'; // for JetBrains IDE only supports yen

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

using namespace std;

//===================================== template =========================================================

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int X; cin >> X;
    if (X == 7 || X == 5 || X == 3) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}