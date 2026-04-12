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
vector<int> dx = {1,0};
vector<int> dy = {0,1};
void dfs(int H,int W,int nx,int ny,vector<vector<char>> &ban){
    ban.at(nx).at(ny) = '.';
    /*for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            cout << ban.at(i).at(j);
        }
        cout << endl;
    }
    cout << endl;*/
    for(int i = 0;i<2;i++){
        if(dx.at(i)+nx < 0 || dx.at(i)+nx >= H || dy.at(i)+ny < 0 || dy.at(i)+ny >= W) continue;
        if(ban.at(dx.at(i)+nx).at(dy.at(i)+ny) != '#') continue;
        dfs(H,W,nx+dx.at(i),dy.at(i)+ny,ban);
        return;
    }
}

int main() {
    int H,W;cin >> H >> W;
    vector<vector<char>> ban(H,vector<char>(W));
    for(int i = 0;i<H;i++)for(int j = 0;j<W;j++)cin >> ban.at(i).at(j);
    
    dfs(H,W,0,0,ban);
    string ans = "Possible";
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            if(ban.at(i).at(j) != '.') ans = "Impossible";
        }
    }
    cout << ans << endl;
}
