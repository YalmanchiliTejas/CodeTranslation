#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> q;
    int a;
    REP(i, n) {
        cin >> a;
        if (q.empty()) {
            q.push_back(a);
        } else {
            auto x = lower_bound(ALL(q), a);
            if (x == q.begin()) {
                auto x = upper_bound(ALL(q), a);
                q.insert(x, a);
            } else {
                q.erase(x - 1);
                auto x = upper_bound(ALL(q), a);
                q.insert(x, a);
            }
        }
    }
    cout << q.size() << endl;
}
