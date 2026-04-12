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
vector<long long> level(51);
vector<long long> paty(51);
long long ans = 0;

long long dfs(long long X,int L){
    if(L == 0){
        if(X == 1) ans++;
        return ans;
    }
    if(X < 1+level.at(L-1)){
        X--;
        dfs(X,L-1);
    }
    else if(1+level.at(L-1) == X){
        ans += paty.at(L-1);
        return ans;
    }
    else if(X == level.at(L-1)+2){
        ans += paty.at(L-1)+1;
        return ans;
    }
    else if(X > level.at(L-1)+2 && X < level.at(L)){
        ans += paty.at(L-1)+1;
        X -= level.at(L-1)+2;
        dfs(X,L-1);
    }
    else if(X == level.at(L)){
        ans += paty.at(L);
        return ans;
    }
}

int main() {
    int N;cin >> N;
    long long X;cin >> X;
    paty.at(0) = 1;
    level.at(0) = 1;
    for(int i = 1;i<51;i++){
        level.at(i) = level.at(i-1)*2+3;
        paty.at(i) = paty.at(i-1)*2+1;
    }
    long long OUTPUT = dfs(X,N);
    cout << OUTPUT << endl;
}
