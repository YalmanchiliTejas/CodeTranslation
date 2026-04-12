#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cout << (#x) << " = " << (x) << "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, k, n) for (int i = (k); i < (int)(n); ++ i)
#define ALL(r) r.begin(), r.end()
#define YES puts("YES")
#define Yes puts("Yes")
#define NO puts("NO")
#define No puts("No")
#define IMP puts("IMPOSSIBLE")
#define Imp puts("Impossible")
#define pb push_back

template<typename T> T DUP(T x, T y) { return (x + y - 1) / y; };
template <typename A, size_t N, typename T>
void arrayFill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
using ll = int64_t;
using vint = vector<int32_t>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pint = pair<int32_t, int32_t>;
using setint = unordered_set<int32_t>;
using setstr = unordered_set<string>;
using qint = queue<int32_t>;

constexpr std::int32_t INF = 1001001001;

void Main() {
    int h, w;
    cin >> h >> w;
    vstr a(h);
    rep(i, h)cin >> a[i];

    setint remove_row;
    setint remove_col;

    rep(i, h) {
        bool flag = true;
        rep(j, w) {
            if (a[i][j] == '#')flag = false;
        }
        if (flag)remove_row.insert(i);
    }

    rep(j, w) {
        bool flag = true;
        rep(i, h) {
            if (a[i][j] == '#')flag = false;
        }
        if (flag)remove_col.insert(j);
    }

    vstr ans;
    rep(i, h) {
        if (remove_row.count(i) == 1)continue;
        ans.push_back("");
        rep(j, w) {
            if (remove_col.count(j) == 1)continue;
            ans.back().push_back(a[i][j]);
        }
    }

    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
