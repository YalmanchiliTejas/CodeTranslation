#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define ln '\n'
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
//const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (1) {
        int N,L,R; cin >> N >> L >> R;
        if (N+L+R==0) break;
        vector<int> A(N);
        rep(i,N) cin >> A[i];

        int ans = 0;
        for (int i = L; i <= R; ++i) {
            bool flag = (N&1 ? 0 : 1);
            rep(j,N) {
                if (i%A[j]==0) {
                    if (j&1) flag = 0;
                    else flag = 1;
                    break; 
                }
            }
            if (flag) ans++;
        }
        cout << ans << ln;
    }
}

