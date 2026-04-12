#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t; using i64 = int64_t; using f64 = double_t; using str = string;
template <typename T> using vec = vector<T>;
template <typename T> using heap = priority_queue<T, vec<T>, greater<T>>;
#define times(n, i) for (i32 i = 0; i < (n); ++i)
#define range(n, m, i) for (i32 i = (n); i < (m); ++i)
#define upto(n, m, i) for (i32 i = (n); i <= (m); ++i)
#define downto(n, m, i) for (i32 i = (n); i >= (m); --i)
#define foreach(xs, x) for (auto &x : (xs))
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define uniqueall(xs) (xs).erase(unique(all(xs)), (xs).end())
#define maximum(xs) (*max_element(all(xs)))
#define minimum(xs) (*min_element(all(xs)))
#define even(x) (((x) & 1) == 0)
#define odd(x) (((x) & 1) == 1)
#define append emplace_back
const i64 MOD = 1000000007;

i32 h, w;
str m[8];
str r[8];

i32 oy[2] = { 0, 1 };
i32 ox[2] = { 1, 0 };

bool rec(i32 y, i32 x) {
    if (m[y][x] == '.')
        return false;

    r[y][x] = '#';
    if (y == h-1 && x == w-1)
        return true;

    bool b[2] = { false, false };
    times(2, i) {
        i32 ny = y + oy[i];
        i32 nx = x + ox[i];
        b[i] = ny < h && nx < w && m[ny][nx] == '#';
    }
    if (b[0] && b[1]) {
        return false;
    }
    times(2, i) {
        if (b[i]) {
            return rec(y+oy[i], x+ox[i]);
        }
    }
    return false;
}

i32 main()
{
    cin >> h >> w;
    times(h, i) {
        cin >> m[i];
        r[i] = "";
        times(w, j) {
            r[i] += '.';
        }
    }

    bool b = rec(0, 0);
    if (b) {
        times(h, i) {
            b &= m[i] == r[i];
        }
    }

    cout << (b ? "Possible" : "Impossible") << endl;
    return 0;
}