#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define PUTS(x) cout << (x) << endl;
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define F first
#define S second
#define perm(c)   \
    sort(ALL(c)); \
    for (bool c##p = 1; c##p; c##p = next_permutation(ALL(c)))
#define IntsIn(v, n)                                 \
    auto v = vector<Int>(0);                         \
    for (int v##_i = 0; v##_i < (int)(n); v##_i++) { \
        Int v##_a;                                   \
        cin >> v##_a;                                \
        v.push_back(v##_a);                          \
    }
void setPrecision(int num = 20) {
    std::cout << std::fixed << std::setprecision(num);
}
template <typename T>
T Max(T a) {
    return a;
}
template <typename T, typename... Args>
T Max(T a, Args... args) {
    return std::max(Max(args...), a);
}
template <typename T>
T Min(T a) {
    return a;
}
template <typename T, typename... Args>
T Min(T a, Args... args) {
    return std::min(Min(args...), a);
}
template <typename T>
bool vector_contains(std::vector<T> vec, T value) {
    return (std::distance(vec.begin(), std::find(vec.begin(), vec.end(), value)) != vec.size());
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
int main() {
    int h, w;
    cin >> h >> w;
    auto v = vector<pair<int, int>>(0);
    rep(i, h) {
        rep(j, w) {
            char a;
            cin >> a;
            if (a == '#') v.PB(MP(i, j));
        }
    }
    auto v2 = v;
    sort(ALL(v), [](const pair<int, int> &a, const pair<int, int> b) {
        return (a.F < b.F);
    });
    sort(ALL(v2), [](const pair<int, int> &a, const pair<int, int> b) {
        return (a.S < b.S);
    });
    puts(v == v2 ? "Possible" : "Impossible");
}
