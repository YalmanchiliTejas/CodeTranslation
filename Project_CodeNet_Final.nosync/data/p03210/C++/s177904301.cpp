#include <bits/stdc++.h>
using namespace std;

struct Benri {
    Benri() {
        std::cin.tie(0); ios::sync_with_stdio(false);
        cout << fixed << setprecision(12);
    }
} benri;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353




int main() {
    int x; cin >> x;
    if(x == 7 || x == 5 || x == 3) cout << "YES" << endl;
    else cout << "NO" << endl;
}


