// finish date: 2019/2/9

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
//#define input(name)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;

int K, N;
string S;


ll dfs(int pos, int tmpK, bool flag = false) {
    if (tmpK == 0) {
        return (ll) 1;
    }
    if (pos >= N) {
        return (ll) 0;
    }
    ll ans = 0;
//    0にする
    bool is0 = ((S[pos] - '0') == 0);
    ans += dfs(pos + 1, tmpK, flag | !is0);
    if (flag) {
        ans += 9 * dfs(pos + 1, tmpK - 1, true);
    } else {
        //0以外
        int n = (S[pos] - '0') - 1;
        if (n > 0) {
            ans += n * dfs(pos + 1, tmpK - 1, true);
        }
        if (S[pos] - '0' != 0) {
            ans += dfs(pos + 1, tmpK - 1, false);
        }
    }
    return ans;

}

int main() {
    cin >> S >> K;
    N = S.length();
    vi arr;
    ll ans = dfs(0, K);
    cout << ans << endl;


    return 0;
}
