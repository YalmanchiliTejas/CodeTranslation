// #pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define String std::string
#define fi first
#define se second
#define mp std::make_pair
#define Pair std::pair<int, int>
#define Map std::map< int, int >
#define Vector std::vector<int>
 
using std::cin;
using std::cout;
using std::endl;
 
typedef long long ll;
typedef unsigned long long ull;
 
const int N = 100000 + 5;
const int M = 1000 + 5;
const int K = 1e7 + 5;
const int MOD = 1e9 + 7;
const int inv2 = 500000004;
const ull BASE = 19260817;
const int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };
const int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };
const double PI = acos(-1);
 
template<class T>
inline T readT() {
    T res = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) res = (res << 1) + (res << 3) + ch - '0';
    return res * f;
}
#define read readT<int>

int n; ll x;
ll f[55], p[55];

ll dfs(int n, ll x) {
    if (n == 0) {
        return x <= 0 ? 0 : 1;
    } else if (x <= 1 + f[n - 1]) {
        return dfs(n - 1, x - 1);
    } else {
        return p[n - 1] + dfs(n - 1, x - f[n - 1] - 2) + 1;
    }
}

int main() {
    scanf("%d %lld", &n, &x);
    f[0] = p[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 2 * f[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }
    printf("%lld\n", dfs(n, x));
    return 0;
}