// 基本テンプレート (縮小版)

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
typedef pair<int, int> pii;
typedef long long ll;
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

int N, a[200010];

signed main() {
    cin >> N;
    rep(i,0,N) cin >> a[i];

    deque<int> ans;
    rep(i,0,N) {
        if(N % 2) {
            if(i % 2) ans.push_back(a[i]);
            else ans.push_front(a[i]);
        }
        else {
            if(i % 2) ans.push_front(a[i]);
            else ans.push_back(a[i]);
        }
    }
    rep(i,0,N) {
        if(i == 0) printf("%lld", ans[i]);
        else printf(" %lld", ans[i]);
    }
    cout << endl;
    return 0;
}