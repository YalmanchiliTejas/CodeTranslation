#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int A,B,C,X,Y;cin  >> A >> B >> C >> X >> Y;

    int ma = max(X,Y);
    int mi = min(X,Y);

    int a1 = ma*C*2;
    int a2 = mi*C*2 + abs(mi - X)*A + abs(mi - Y)*B;
    int a3 = A*X + B*Y;

    int ans = 1 << 30;
    ans = min(ans,a1);
    ans = min(ans,a2);
    ans = min(ans,a3);

    cout << ans << endl;
}
