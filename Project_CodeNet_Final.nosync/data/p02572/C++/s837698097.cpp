#include <bits/stdc++.h>
#define fastIO() ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define dpow(x) ((x) * (x))
#define mabs(x) ((x) > 0 ? (x) : (-(x)))
#define in1(x) cin >> x
#define in2(x, y) cin >> x >> y
#define in3(x, y, z) cin >> x >> y >> z
#define in4(x, y, z, w) cin >> x >> y >> z >> w
#define rep(i, x, y) for (int i = x, a, b, c; i <= y; i++)
#define rep2(i, j, N, M) rep(i, 1, N) rep(j, 1, M)
#define repneq(i, x, y) for (int i = x, a, b, c; i < y; i++)
#define revrep(i, y, x) for (int i = y; i >= x; i--)
#define iterrep(item, items) for (auto item : items)
#define iterrefrep(item, items) for (auto &item : items)
#define EL cout << '\n'
// #define endl '\n'
#define all(x) x.begin(), x.end()
#define ball(x, i) x.begin() + i, x.end()
#define PQ priority_queue
using namespace std;
int DX[] = {-1, 0, 1, 0}, DY[] = {0, 1, 0, -1};
enum DIR { RIGHT, DOWN, LEFT, UP };
template <class T> int GetSign(T t) {
    if (t < 0)
        return -1;
    else if (t > 0)
        return 1;
    return 0;
}
inline int getSegSize(int N) { return 1 << ((int)ceil(log2(N)) + 1); }
template <class T> inline int getIdx(const vector<T> &v, T data) { return lower_bound(all(v), data) - v.begin(); }
template <class T> istream &operator>>(istream &stream, vector<T> &v) {
    repneq(i, 0, v.size()) stream >> v[i];
    return stream;
}
template <class T1, class T2> class Pair {
  public:
    T1 x;
    T2 y;
    Pair(T1 x_ = T1(), T2 y_ = T2()) : x(x_), y(y_) {}
    bool operator<(const Pair &p) const { return x == p.x ? y < p.y : x < p.x; }
    bool operator<=(const Pair &p) const { return x == p.x ? y <= p.y : x <= p.x; }
    bool operator>(const Pair &p) const { return x == p.x ? y > p.y : x > p.x; }
    bool operator!=(const Pair<T1, T2> &p) const { return x != p.x || y != p.y; }
    bool operator==(const Pair<T1, T2> &p) const { return x == p.x && y == p.y; }
    friend Pair<T1, T2> operator+(const Pair<T1, T2> &a, const Pair<T1, T2> &b) { return Pair<T1, T2>(a.x + b.x, a.y + b.y); }
    friend Pair<T1, T2> operator-(const Pair<T1, T2> &a, const Pair<T1, T2> &b) { return Pair<T1, T2>(a.x - b.x, a.y - b.y); }
    friend istream &operator>>(istream &stream, Pair &p) {
        stream >> p.x >> p.y;
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const Pair &p) {
        stream << p.x << ' ' << p.y;
        return stream;
    }
};
template <class T> void printVector(const vector<T> &v, string sep = " ", string end = "\n") {
    if (v.empty()) return;
    for_each(v.begin(), v.end() - 1, [=](const T &a) { cout << a << sep; });
    cout << v[v.size() - 1] << end;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LB;
typedef Pair<int, int> PII;
typedef Pair<LL, LL> PLL;
typedef vector<vector<int>> ADJGRAPH;
template <class T> T CCW(Pair<T, T> &a, Pair<T, T> &b, Pair<T, T> &c) { return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y); }
template <class T> T Factorial(T a) {
    T ret = 1;
    rep(i, 1, a) ret = ret * i;
    return ret;
}
template <class T> T Factorial(T a, T mod) {
    T ret = 1;
    rep(i, 1, a) ret = ret * i % mod;
    return ret;
}
bool CrossLine(vector<PLL> L1, vector<PLL> L2) {
    LL ccw1 = GetSign(CCW(L1[0], L1[1], L2[0])) * GetSign(CCW(L1[0], L1[1], L2[1]));
    LL ccw2 = GetSign(CCW(L2[0], L2[1], L1[0])) * GetSign(CCW(L2[0], L2[1], L1[1]));
    if (!ccw1 && !ccw2) {
        if (L1[0] > L1[1]) swap(L1[0], L1[1]);
        if (L2[0] > L2[1]) swap(L2[0], L2[1]);
        return (L1[0] <= L2[1] && L2[0] <= L1[1]);
    }
    return (ccw1 <= 0 && ccw2 <= 0);
}
namespace Constants {
const int MAXX = 50;
const int MAXM = 300;
const int INF = 1 << 29;
const LL LINF = 1LL << 50;
const double PI = 3.1415926535;
const LL MOD = 1000000007LL;
}; // namespace Constants
//// ---------------------------- Solve Space

int main() {
    fastIO();
    int N;
    LL S = 0;
    LL R = 0;
    in1(N);
    vector<LL> V(N);
    repneq(i, 0, N) {
        in1(V[i]);
        S += V[i];
        S %= Constants::MOD;
    }
    repneq(i, 0, N) {
        S -= V[i];
        S = (S + 2 * Constants::MOD) % Constants::MOD;
        R += V[i] * S % Constants::MOD;
        R %= Constants::MOD;
    }
    cout << R;
    return 0;
}