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
    return a * b / gcd(a, b);
}

vector<vector<bool>> Edge(10,vector<bool>(10));

int main() {
    int N,M;cin >> N >> M;
    for(int i = 0;i<M;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        Edge.at(a).at(b) = true;
        Edge.at(b).at(a) = true;
    }
    vector<int> permutation(N);
    vector<bool> V(N,false);
    bool ok = true;
    int ans = 0;
    for(int i = 0;i<N;i++) permutation.at(i) = i;
    do{
        V.assign(N,false);
        V.at(0) = true;
        if(permutation.at(0) != 0) continue;
        for(int i = 0;i<N-1;i++){
            int from = permutation.at(i);
            int to = permutation.at(i+1);
            if(V.at(to) || !Edge.at(from).at(to)) ok = false;
            else V.at(to) = true;
            //cout << from << " " << to << " " << ok << endl;
        }
        if(ok) ans++;
        ok = true;
    }while(next_permutation(permutation.begin(),permutation.end()));

    cout << ans << endl;
}