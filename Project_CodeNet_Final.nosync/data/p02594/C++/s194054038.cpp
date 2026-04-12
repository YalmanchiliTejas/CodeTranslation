#pragma GCC optimize(2)

#include "bits/stdc++.h"

using namespace std;

#define all(a) begin(a), end(a)
#define MOD 1000000007
#define PII pair<int, int>
#define REP(x, l, u) for (ll x = l; x < u; x++)
#define RED(x, l, u) for (ll x = l; x >= u; x--)
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
typedef vector<int> VI;
typedef long long ll;

ll quick_pow(ll a, ll b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = a * res;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    a = abs(a), b = abs(b);
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool is_prime(int n) {
    if (n == 0)return false;
    if (n == 1)return false;
    if (n == 2)return true;
    if (n % 2 == 0)
        return false;
    int j = sqrt(n);
    for (int i = 2; i <= j; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll reverse_num(ll n) {
    ll x = 0, t = n;
    while (t != 0) {
        x = x * 10 + t % 10;
        t /= 10;
    }
    return x;
}

void solve() {
    //    freopen("C:\\Users\\26019\\Downloads\\P1195_4.in", "r", stdin);
    //    fclose(stdin);
    int t = 1;
//    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x >=30) cout << "Yes";
        else cout <<"No";
    }
}

int main() {
    // 加速输入和输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

