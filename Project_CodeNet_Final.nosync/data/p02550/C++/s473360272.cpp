#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

bool vis[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, x, m;
    cin >> n >> x >> m;

    long long ret = 0;
    for (long long i=0; i<n; i++) {
        ret += x;
        vis[x] = true;
        x = x * x % m;
        if (vis[x]) {
            vector<long long> pref;
            pref.push_back(x);
            long long u = x * x % m;
            while (u != x) {
                pref.push_back(pref.back() + u);
                u = u * u % m;
            }
            ret += (n - i - 1) / (int) pref.size() * pref.back() + ((n - i - 1) % (int) pref.size() > 0 ? pref[(n - i - 1) % (int) pref.size() - 1] : 0);
            break;
        }
    }
    cout << ret << "\n";

    return 0;
}
