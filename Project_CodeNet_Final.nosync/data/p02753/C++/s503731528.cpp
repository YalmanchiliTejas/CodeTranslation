#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    string S;
    cin >> S;
    int a = 0, b = 0;
    rep(i, 3) {
        if (S[i] == 'A') a++;
        if (S[i] == 'B') b++;
    }

    if (a > 0 && b > 0) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}