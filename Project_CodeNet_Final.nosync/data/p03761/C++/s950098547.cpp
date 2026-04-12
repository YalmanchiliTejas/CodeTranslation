#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int n;
    cin >> n;
    vector<int> alpha(26, 0);
    vector<string> S(n);
    rep(i, n) {
        cin >> S[i];
    }

    rep(i, S[0].size()) {
        alpha[S[0][i] - 'a']++;
    }

    repd(i, 1, n) {
        rep(j, 26) {
            if (alpha[j] == 0) continue;
            char ct = (char)('a' + j);
            int cnt = 0;
            rep(k, S[i].size()) {
                if (S[i][k] == ct) cnt++;
            }
            chmin(alpha[j], cnt);
        }
    }

    rep(i, 26) {
        rep(j, alpha[i]) {
            cout << (char)('a' + i);
        }
    }

    cout << endl;
    return 0;
}