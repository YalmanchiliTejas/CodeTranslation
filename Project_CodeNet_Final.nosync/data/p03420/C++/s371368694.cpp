#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MOD = 1000000007;

int main(){
    int N, K; cin >> N >> K;

    ll ans = 0;
    for (int i = 1; i <= N; i++){
        ll tmp = max(i-K,0)*(N/i);
        tmp += max(N%i-K+1,0);
        ans += tmp;
        if (K==0) ans--;
    }

    cout << ans << endl;
}