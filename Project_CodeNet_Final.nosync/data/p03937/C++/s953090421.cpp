#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int H,W;
    cin >> H >> W;
    int cnt = 0;
    REP(i,H){
        string str; cin >> str;
        for(const auto &it: str) if (it == '#') cnt ++;
    }
    if (cnt == (H+W-1)) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

}

int main() {
    solve();
    return 0;
}
