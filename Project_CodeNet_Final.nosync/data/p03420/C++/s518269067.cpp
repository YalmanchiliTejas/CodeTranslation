#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
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
    LL N,K;cin >> N >> K;
    LL ans = 0;
    if(K == 0){
        cout << N*N << endl;
    }
    else{
        for(int i = 1;i <= N;++i) {
            int tmp = N/i;
            int nokori = N-tmp*i;
            if(nokori > 0){
                if(nokori >= K)ans += nokori - K + 1;
            }
            if(i-K > 0)ans += (i-K)*tmp;
        }

        cout << ans << endl;
    }

}