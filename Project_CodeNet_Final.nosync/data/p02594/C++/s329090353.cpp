#include <bits/stdc++.h>
using namespace std;
void Main();

using i8  = int8_t;   /* -128 ~ 127 */
using u8  = uint8_t;  /* 0 ~ 255 */
using i16 = int16_t;  /* -32,768 ~ 32,767 */
using u16 = uint16_t; /* 0 ~ 65,535 */
using i32 = int32_t;  /* -2,147,483,648 ~ 2,147,483,647 */
using u32 = uint32_t; /* 0 ~ 4,294,967,295 */
using i64 = int64_t;  /* -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 */
using u64 = uint64_t; /* 0 ~ 18,446,744,073,709,551,615 */
using f32 = float;    /* (-3.4 * 10^38) ~ (3.4 * 10^38) */
using f64 = double;   /* (-1.7 * 10^308) ~ (1.7 * 10^308) */
using f80 = __float80;
template <class T> using Vec = vector<T>;
constexpr i64 INF = 1010000000000000017;
constexpr i64 MOD = 1e9 + 7;
constexpr f64 EPS = 1e-12;
constexpr f64 PI = 3.14159265358979323846;
#define YN(y, n, b) (b? y : n)
#define ALL(v) v.begin(), v.end()
#define GCD(a, b) __gcd(a, b) /* 最大公約数 */
#define LCM(a, b) a / __gcd(a, b) * b /* 最小公倍数 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

void Main() {
    i32 X;
    cin >> X;
    cout << YN("Yes", "No", X >= 30) << endl;
}
