#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma region Macros
/***
 * @author uesugi
 * @file AtCoder用テンプレート
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;

#define _OVERLOAD3(_1, _2, _3, name, ...) name
#define _REP(i, n) REPI(i, 0, n)
#define REPI(i, a, b) for (int i = int(a), i##_len = (b); i < i##_len; ++i)
#define REP(...)                          \
    _OVERLOAD3(__VA_ARGS__, REPI, _REP, ) \
    (__VA_ARGS__)

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

/**
 * 最大値更新
 * @param T &a 更新対象
 * @param const T &b 判定対象
 * @return 更新有無
 */
template <class T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

/**
 * 最小値更新
 * @param T &a 更新対象
 * @param const T &b 判定対象
 * @return 更新有無
 */
template <class T>
inline bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

/**
 * overload
 * 入力を配列に格納
 * 配列の長さ分入力を格納
 * @param std::istream &is 入力ストリーム
 * @param std::vector<T> &vec 格納先配列
 * @return std::istream 
 */
template <typename T>
inline std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (T &element : vec) {
        is >> element;
    }
    return is;
}

template <typename T1, typename T2>
inline std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

/**
 * overload
 * コンテナの要素を出力する
 * @param std::basic_ostream<Ch, Tr> &os 出力ストリーム
 * @param Container const &x 出力対象コンテナ
 * @return std::basic_ostream<Ch, Tr> 
 */
template <class Ch, class Tr, class Container>
inline std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, Container const &x) {
    bool first = true;
    for (auto &y : x) {
        if (first) {
            first = false;
        } else {
            os << " ";
        }
        os << y;
    }
    return os;
}

// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0, a1, a2, a3, a4, x, ...) x
#define DEBUG_1(x1) cout << #x1 << ": " << x1 << "\n"
#define DEBUG_2(x1, x2) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << "\n"
#define DEBUG_3(x1, x2, x3) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << "\n"
#define DEBUG_4(x1, x2, x3, x4) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << "\n"
#define DEBUG_5(x1, x2, x3, x4, x5) cout << #x1 << ": " << x1 << ", " #x2 << ": " << x2 << ", " #x3 << ": " << x3 << ", " #x4 << ": " << x4 << ", " #x5 << ": " << x5 << "\n"
#ifdef _DEBUG
/**
 * デバッグ用出力メソッド
 * 変数名及び値を出力
 * -D_DEBUG オプション付きビルド時のみ有効
 * @param 可変長引数
 */
#define DEBUG(...)                                                        \
    CHOOSE((__VA_ARGS__, DEBUG_5, DEBUG_4, DEBUG_3, DEBUG_2, DEBUG_1, ~)) \
    (__VA_ARGS__)

#define DEBUG_TIME() cout << "debug_time: " << clock() - START_TIME << "\n"
clock_t START_TIME = clock();
#else
#define DEBUG(...)
#define DEBUG_TIME()
#endif

#pragma endregion

/**
 * 処理
 * @return void
 */
void Main() {
    string S;
    cin >> S;
    if (S[0] == S[1] && S[0] == S[2]) {
        cout << "No";
        return;
    }
    cout << "Yes";
}

#pragma region main
/**
 * main
 * 共通処理
 * @return signed
 */
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << std::fixed;
    cout.precision(20);
    Main();
    cout << flush;
}
#pragma endregion
