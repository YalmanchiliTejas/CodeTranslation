/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 10010010010010;
const long long MOD = 1000000007;
typedef pair<int,int> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b ;
}
//dp[i][j][k]:i桁目まで見て、0以外をj個使ってそれまで一致している時k=0
long long dp[105][4][2];

int main() {
    string S;cin >> S;
    int K;cin >> K;
    int N = S.size();
    for(int i = 0;i<105;i++) for(int j = 0;j<4;j++) for(int k = 0;k<2;k++) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    //状態を全列挙
    for(int i = 0;i<N;i++){
        for(int j = 0;j<4;j++){
            for(int k = 0;k<2;k++){
                //Sのi桁目を見る
                int nowdigit = S.at(i)-'0';
                //i桁目として0~9の10通り
                for(int l = 0;l<10;l++){
                    int nextj = j,nextk = k;
                    //i桁目が0でないなら次桁のjを加算する
                    if(l != 0) nextj++;
                    //i桁目として0以外を使えるのはK回まで
                    if(nextj > K) continue;

                    //i-1桁目まで今まで一致している時
                    if(k == 0){
                        //i桁目の候補がnowdigitより大きかったらダメ
                        if(l > nowdigit) continue;
                        //i桁目の候補がnowdigitより小さいとkは0になる
                        if(l < nowdigit) nextk = 1;
                    }
                    dp[i+1][nextj][nextk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[N][K][0]+dp[N][K][1] << endl;
}
