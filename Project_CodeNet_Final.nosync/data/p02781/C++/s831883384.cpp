#include <bits/stdc++.h>
using namespace std;

typedef int64_t Int;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << endl; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) cout << " ";
    cout << fixed << setprecision(15) << head;
    print_space_enable = true;
    print(std::forward<Tail>(tail)...);
}

template<typename T>
void print(vector<T> v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << std::endl;
}

Int dp[1000][5];

int main() {
    string s;
    Int k;
    cin >> s >> k;
    Int n = s.size();
    dp[0][0] = 1;
    Int cnt = 0;
    for (Int i = 0; i < (Int)n; i++) {
        for (Int j = 0; j <= (Int)k; j++) {
            dp[i + 1][j] += dp[i][j];
        }
        for (Int j = 0; j < (Int)k; j++) {
            if (cnt == j) {
                dp[i + 1][j + 1] += (dp[i][j] - 1) * 9 + s[i] - '0';
            } else {
                dp[i + 1][j + 1] += dp[i][j] * 9;
            }
        }
        if (s[i] != '0') cnt++;
    }
    // for (Int i = 0; i < (Int)4; i++) {
    //     for (Int j = 0; j <= (Int)n; j++) {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    print(dp[n][k]);
    return 0;
}