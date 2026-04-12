//#include <bits/stdc++.h>
#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <iomanip>

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define ROF(i, j, k) for(int i = (int)(j); i >= (int)(k); --i)
#define FORLL(i, n, m) for(long long i = n; i < (long long)(m); i++)
#define SORT(v, n) sort(v, v+n)
#define REVERSE(v) reverse((v).begin(), (v).end())

using namespace std;
using ll = long long;
const ll MOD=1000000007LL;
typedef pair<int, int> P;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}

ll dp[10010][101][2];
int N, D;
string K;

void solve(){
    // dp[dgt][d][isless] := 先頭から確定した桁数dgt, 各桁の数字の和をDで割った値d, K未満フラグisless
    dp[0][0][0] = 1;
    for(int dgt=0; dgt<N; dgt++) for(int d=0; d<D; d++) for(int isless=0; isless<2; isless++) {
        int c = K[dgt] - '0';
        for(int nxt=0; nxt<10; nxt++) {
            //Kのdgt桁よりも小さい値の場合 ... 次のdgt+1桁の 数字の総和d+nxt で isless=1な配列に isless=0,1の両方を加算.
            if (nxt < c) (dp[dgt + 1][(d + nxt) % D][1] += dp[dgt][d][isless]%MOD)%=MOD;
            //Kのdgt桁と同じ値の場合      ... isless=0, 1をそれぞれ加算
            else if(nxt == c) (dp[dgt + 1][(d + nxt) % D][isless] += dp[dgt][d][isless]%MOD)%=MOD;
            //Kのdgt桁よりも大きい値の場合 ... 以前の桁で値が小さいことが分かっているなら更新
            else {
                if(isless) (dp[dgt + 1][(d + nxt) % D][isless] += dp[dgt][d][isless]%MOD)%=MOD;
            }
        }
    }
    // 余りが0かつK未満 + 余りが0かつkと等しい - 1<=x<=Kなのでx=0を除く
    cout << ((dp[N][0][0] + dp[N][0][1])%MOD + MOD - 1)%MOD << endl;
}

int main(void){
    cin >> K >> D;
    N = K.size();
    memset(dp,0,sizeof(dp));
    solve();
    return 0;
}