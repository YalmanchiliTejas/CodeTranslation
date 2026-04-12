#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iterator>  // std::back_inserter()
#include <set>
#include <algorithm>  // std::copy()
#include <functional>  // std::greater<T>()
#include <utility>  // std::swap()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値
#include <cmath>
#include <climits>  // INT_MIN
#include <cctype>  // std::isdigit()
using namespace std;

#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define MIN(vec) min_element(ALL((vec)))  // イテレータのため、値を取り出すときは * を先頭につける
#define MAX(vec) max_element(ALL((vec)))
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define SUM(vec) accumulate(ALL((vec)), 0)  // 0 は初期値
#define COPY(vec1, vec2) copy(ALL(vec1), back_inserter(vec2))  // vec1をvec2にコピーする vec2は空にしておく必要あり
typedef long long ll;

const int MOD = 1000000007;  // 1 000 000 007

ll bans[60];
ll paty[60];

ll f(ll n, ll x) {
    if (n == 0) return x <= 0 ? 0 : 1;
    else if (x <= 1 + bans[n - 1]) return f(n - 1, x - 1);
    else if (x == 2 + bans[n - 1]) return 1 + paty[n - 1];
    else return paty[n - 1] + 1 + f(n - 1, x - 2 - bans[n - 1]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, X;
    cin >> N >> X;
    
    bans[0] = 1;
    paty[0] = 1;
    for (int i = 1; i < N; ++i) {
        bans[i] = 2*bans[i - 1] + 3;
        paty[i] = 2*paty[i - 1] + 1;
    }
    
    cout << f(N, X) << "\n";

    return 0;
}
