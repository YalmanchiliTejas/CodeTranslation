#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }


int main(){
    int n;
    cin >> n;
    vector<string> S(n);
    vector<vector<int>> cnt(n, vector<int>(26, 0));

    rep(i, n) cin >> S[i];

    rep(i, n) {
        for (auto s: S[i]) {
            cnt[i][s - 'a']++;
        }
    }
    vector<int> ans(26, 0);
    rep(j, 26) {
        int res = INF;
        rep(i, n) {
            res = min(res, cnt[i][j]);
        }
        ans[j] = res;
    }

    cout << "";
    rep(j, 26) {
        for (int i=0;i<ans[j];++i) {
            cout << (char)('a' + j);
        }
    }
    cout << endl;
}