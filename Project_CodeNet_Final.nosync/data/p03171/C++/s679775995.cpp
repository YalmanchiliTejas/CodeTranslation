#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
    詰まった時に、別の分野の問題として考え直す（これdpでは？、グラフとしてみればいいのでは？）
    多くの問題はパターンマッチだが、パターンに落とし込むまでが難しく、そのための訓練としてわからない問題をあれこれ色々な角度から考察してみるのではないか
*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n == 0) return 1;

    ll res = modpow(x, n/2);
    if(n%2 == 0) return res*res%mod;
    else return res*res%mod*x%mod;
}

ll power(ll x, ll n){
    if(n == 0) return 1;

    ll res = power(x, n/2);
    if(n%2 == 0) return res*res;
    else return res*res*x;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */

typedef tuple<ll, ll, ll> T;

int n;
vector<vector<ll>> memo(3030, vector<ll>(3030, 0));
vector<ll> a(3030, 0);
vector<vector<bool>>  flg(3030, vector<bool>(3030, false));

ll rec(int l, int r){
    if(flg[l][r]) return memo[l][r];
    flg[l][r] = true;

    if(l==r) return memo[l][r] = a[l];
    return memo[l][r] = max(a[l]-rec(l+1, r), a[r]-rec(l, r-1));
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // 条件はどちらも「（自分の点数）ー（相手の点数）」最大化しようとする
    // 前から取るのがいいのか、後ろから取るのがいいのかは、残った数を使ってゲームの結果が分かれば判断できる
    // dp[i][j] := 区間[i,j]が残ってる時の、「次の手番の人の得点ーそうじゃない人の特点」

    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];

    cout << rec(1, n) << endl;

    
    return 0;
}