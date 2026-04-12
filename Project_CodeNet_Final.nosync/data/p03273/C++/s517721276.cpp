/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG //FOR THE DEBUG! COMMENT OUT THIS WHEN SUBMITTING!
#endif
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
#define WOULD
#define YOU
#define PLEASE
#define ACCEPT
#define MY
#define SUBMISSION
/* I REALLY HOPE MY WISH REACH YOU , ATCODER'S ONLINE JUDGE */
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
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 100100100100;
const long long MOD = 998244353;
typedef pair<long long,long long> P;

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
    return a * b / gcd(a, b);
}

int main() {
    int H,W;cin >> H >> W;
    vector<vector<char>> ban(H,vector<char>(W));
    vector<vector<bool>> choose(H,vector<bool>(W));
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            cin >> ban.at(i).at(j);
            choose.at(i).at(j) = false;
        }
    }
    //縦に見る
    bool ok = true;
    for(int i = 0;i<W;i++){
        ok = true;
        for(int j = 0;j<H;j++){
            if(ban.at(j).at(i) != '.') ok = false;
        }
        if(ok){
            for(int k = 0;k<H;k++){
                choose.at(k).at(i) = true;
            }
        }
        ok = true;
    }
    //横に見る
    for(int i = 0;i<H;i++){
        ok = true;
        for(int j = 0;j<W;j++){
            if(ban.at(i).at(j) != '.') ok = false;
        }
        if(ok){
            for(int k = 0;k<W;k++){
                choose.at(i).at(k) = true;
            }
        }
        ok = true;
    }
    bool OUTPUTok = false;
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            if(choose.at(i).at(j)) continue;
            cout << ban.at(i).at(j);
            OUTPUTok = true;
        }
        if(OUTPUTok) cout << endl;
        OUTPUTok = false;
    }
}