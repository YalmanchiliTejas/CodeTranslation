#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
// mt19937 rnd(1);

const int P = 998244353;

void add(int &a, int b, int p = P) {
    a += b;
    if (a >= p) {
        a -= p;
    }
}

void sub(int &a, int b, int p = P) {
    a -= b;
    if (a < 0) {
        a += p;
    }
}


void mul(int &a, int b, int p = P) {
    a = ll(a) * b % p;
}

int binPow(int a, int b, int p = P) {
    int res = 1;
    for (; b > 0; b >>= 1) {
        if (b & 1) {
            mul(res, a, p);
        }
        mul(a, a, p);
    }
    return res;
}

int reverse(int a, int p = P) {
    return binPow(a, p - 2, p);
}

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;      

    int n;
    cin >> n;

    vector<int> r(n + 1);

    for (int i = 1; i <= n; ++i) {
        r[i] = reverse(i);
    }

    int sum = 1;
    int cur = 1;

    for (int i = 1; i < n / 2; ++i) {
        mul(cur, n - i + 1);
        mul(cur, r[i]);
        mul(cur, 2);
        add(sum, cur);
    } 

    mul(sum, 2);

    int res = binPow(3, n);

    sub(res, sum);

    cout << res << endl;

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

 