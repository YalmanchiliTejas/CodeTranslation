/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG
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
#include <set> // set,multiset
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
#define endl "\n";
using namespace std;

const long long INF = 4000000000000000001;
const int inf = 1001001001;
const int MOD = 1000000007;
typedef pair<long long,long long> P;

void chmax(long long &a,long long b){if(a < b) a = b;}
void chmin(long long &a,long long b){if(a > b) a = b;}

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //When end-of-a bit is 1, times simple N.
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



int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;cin >> N;
    string S;cin >> S;
    for(int i = 0;i<(1<<2);i++){
        bitset<2> B(i);
        string ans = "";
        if(B.test(0)) ans += "S";
        else ans += "W";
        if(B.test(1)) ans += "S";
        else ans += "W";
        //連続する2匹を全探索すると全匹決まる（すげ江）
        for(int j = 1;j<N;j++){
            if(ans.at(j) == 'S' && S.at(j) == 'o'){
                ans += ans.at(j-1);
            }
            else if(ans.at(j) == 'S' && S.at(j) == 'x'){
                if(ans.at(j-1) == 'S') ans += "W";
                if(ans.at(j-1) == 'W') ans += "S";
            }
            if(ans.at(j) == 'W' && S.at(j) == 'x'){
                ans += ans.at(j-1);
            }
            else if(ans.at(j) == 'W' && S.at(j) == 'o'){
                if(ans.at(j-1) == 'S') ans += "W";
                if(ans.at(j-1) == 'W') ans += "S";
            }
        }
        if(ans.front() != ans.back()) continue;
        ans.pop_back();
        bool ok = false;
        if(ans.front() == 'S'){
            if(S.front() == 'o'){
                if(ans.at(1) == ans.back()) ok = true;
            }
            else{
                if(ans.at(1) != ans.back()) ok = true;
            }
        }
        else{
            if(S.front() == 'o'){
                if(ans.at(1) != ans.back()) ok = true;
            }
            else{
                if(ans.at(1) == ans.back()) ok = true;
            }
        }
        if(ok){
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}