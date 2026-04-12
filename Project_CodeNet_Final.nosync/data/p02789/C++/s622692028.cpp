#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define NIL -1
typedef long long ll;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll MOD = 1000000007;

void solve() {

    ll n, m;
    cin >> n >> m;

    if(n == m){
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
    return;
}

int main() {
    solve();
    return 0;

}