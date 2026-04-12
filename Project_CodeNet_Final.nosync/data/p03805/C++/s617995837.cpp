#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#include <map>
#include <set>
#include <ios>
#include <cctype>
#include <cstdio>
#include <functional>
#include <cassert>

#define REP(i,a) for(int i = 0;i < (a);++i)
#define FOR(i,a,b) for(int i = (a);i < (b); ++i)
#define FORR(i,a,b) for(int i = (a) - 1;i >=(b);--i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SIZE(obj) (int)(obj).sizeT()
#define YESNO(cond,yes,no){cout <<((cond)?(yes):(no))<<endl; }
#define SORT(list) sort(ALL((list)));
#define RSORT(list) sort((list).rbegin(),(list).rend())
#define ASSERT(cond,mes) assert(cond && mes)

using namespace std;
using ll = long long;

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'050'000'000;

template<typename T>
T round_up(const T& a, const T& b) {
    return (a + (b - 1)) / b;
}

template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2>& p) {
    os << p.first << p.second;
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    REP(i, (int)v.size())is >> v[i];
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
    REP(i, (int)v.size())os << v[i] << endl;
    return os;
}

template <typename T>
T clamp(T& n, T a, T b) {
    if (n < a)n = a;
    if (n > b)n = b;
    return n;
}

template <typename T>
static T GCD(T u, T v) {
    T r;
    while (v != 0) {
        r = u % v;
        u = v;
        v = r;
    }
    return u;
}

template <typename T>
static T LCM(T u, T v) {
    return u / GCD(u, v) * v;
}

bool isAllVisit(const vector<bool>& visit) {
    for (auto&& v : visit) {
        if (!v)return false;
    }
    return true;
}

int solve(int v, const vector<vector<int>>& graph, vector<bool> visit) {
    if (visit[v])return 0;
    visit[v] = true;
    if (isAllVisit(visit))return 1;
    int cnt = 0;
    for (auto&& g : graph[v]) {
        cnt += solve(g, graph, visit);
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);

    REP(i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    vector<bool> visit(N, false);
    cout << solve(0, graph, visit);

    return 0;
}