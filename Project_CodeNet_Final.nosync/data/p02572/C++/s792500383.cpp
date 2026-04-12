#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    LL N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    vector<LL> rui(N+1);
    rui[0] = 0;
    rep(i,N){
        rui[i+1] = rui[i] + A[i];
        rui[i+1] %= MOD;
    }

    LL ans = 0;

    for(int i = 0;i < N-1;i++){
        LL tmp = A[i] * (rui[N] - rui[i+1]);
        tmp %= MOD;
        tmp += MOD;
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    ans += MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
}