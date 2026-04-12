#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

// using mint = modint1000000007;
// using mint = modint998244353;

typedef int64_t Int;
#define all(x) (x).begin(), (x).end()
 
const double EPS = 1e-10;
const Int INF = 1e18;
const int inf = 1e9;
const Int mod = 1e9+7;

bool print_space_enable = false;
void print() { 
    cout << '\n'; 
    print_space_enable = false;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    if (print_space_enable) std::cout << " ";
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
    std::cout << '\n';
}

void solve() {
    Int n, x, m;
    cin >> n >> x >> m;
    Int cur = x;
    Int cycle_start = 0;
    map<Int, Int> mp;
    for (Int i = 0; i < m + 1; i++) {
        if (mp[cur] >= 2) {
            cycle_start = cur;
            break;
        }
        cur = cur * cur % m;
        mp[cur]++;
    }
    Int res = 0;
    cur = x;
    for (Int i = 0; i < m + 1; i++) {
        if (mp[cur] >= 2) {
            break;
        }
        res = (res + cur);
        cur = cur * cur % m;
        n--;
        if (n == 0) {
            print(res);
            return;
        }
    }
    Int cnt = 1;
    Int sum = cycle_start;
    cur = cur * cur % m;
    while (mp[cur] == 1) {
        sum = (sum + cur);
        cur = cur * cur % m;
        cnt++;
    }
    //print(sum);
    Int add = sum * (n / cnt);
    // print(n, cnt, n % cnt);
    res = (res + add);
    cur = cycle_start;
    n %= cnt;
    for (Int i = 0; i < n; i++) {
        res = (res + cur);
        cur = cur * cur % m;
    }
    print(res);
}

int main() {
    solve();
    return 0;
}
