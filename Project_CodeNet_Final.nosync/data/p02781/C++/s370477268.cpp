#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
        return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
        string n;
        int k;
        cin >> n >> k;

        function<ll(int, int, bool)> rec = [&](int i, int j, bool f) {
                static auto dp = make_v(n.length() + 1, k + 1, 2, -1LL);

                if (i == n.length()) {
                        return static_cast<ll>(j == k);
                }

                if (dp[i][j][f] != -1) {
                        return dp[i][j][f];
                }

                int m = f ? n[i] - '0' : 9;
                ll ret = 0LL;

                REP(d, m + 1) {
                        if (d != 0) {
                                if (j >= k) continue;
                                ret += rec(i + 1, j + 1, f && d == m);
                        } else {
                                ret += rec(i + 1, j, f && d == m);
                        }
                }

                return dp[i][j][f] = ret;
        };

        cout << rec(0, 0, true) << endl;

        return 0;
}
