// Akshit Awasthi
#include <bits/stdc++.h>
#define int long long
#define float long double
#define ar array
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define all(x) x.begin(), x.end()
#define deb(...) cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "]\n"
#define deb2(x, y) cerr << #x << " = " << x << "\t" << #y << " = " << y << endl
#define fastio                    \
    std::ios::sync_with_stdio(0); \
    std::cin.tie(NULL);           \
    std::cout.tie(NULL)
#define mod1 1000000007
#define mod2 998244353
#define mod mod1
#define MAX 200015
using namespace std;

template <class T>
istream& operator>>(istream& stream, vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) stream >> v[i];
    return stream;
}
template <class T1, class T2>
istream& operator>>(istream& stream, pair<T1, T2>& p) {
    return stream >> p.first >> p.second;
}
template <class T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) stream << v[i] << ' ';
    stream << '\n';
    return stream;
}
template <class T1, class T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& pair) {
    return stream << pair.first << ' ' << pair.second;
}
int pow(int a, int n) {
    if (n < 0) return 0;
    int ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
int __lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int fact(int n) { return n == 0 ? 1LL : n * fact(n - 1) % mod; }
int inverse(int x, int p = mod) { return pow(x, p - 2); }
int nck(int n, int k, int p = mod) {
    return fact(n) * inverse(fact(k), p) % p * inverse(fact(n - k)) % p;
}

vector<int> arr;

void solve(void) {
    int n;
    cin >> n;
    if (n >= 30) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int32_t main(void) {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("error.txt", "w", stderr);
    // #endif
    fastio;
    // cout.setf(std::ios::unitbuf);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}