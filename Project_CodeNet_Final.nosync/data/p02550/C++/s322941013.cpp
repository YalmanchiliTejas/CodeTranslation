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



int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;cin >> N;
    long long X,M;cin >> X >> M;
    //余りのループを探す
    vector<bool> remainder(100005);
    vector<long long> trase;
    long long now = X;
    long long loop = -1;
    while(true){
        if(remainder.at(now)){
            trase.push_back(now);
            loop = now;
            break;
        }
        remainder.at(now) = true;
        trase.push_back(now);
        now *= now;
        now %= M;
        //cout << now << endl;
    }
    //cout << endl;
    vector<long long> beforeLoop_rui(1);
    long long loopIndex = 0;
    for(long long i = 0;i<trase.size();i++){
        if(trase.at(i) == loop){
            loopIndex = i;
            break;
        }
        beforeLoop_rui.push_back(beforeLoop_rui.at(i)+trase.at(i));
    }
    //ループ入る前にN回終わる時
    if(N <= loopIndex){
        cout << beforeLoop_rui.at(N) << endl;
        return 0;
    }
    N -= loopIndex;
    long long ans = beforeLoop_rui.back();
    vector<long long> loop_rui(1);
    for(long long i = loopIndex;i<trase.size();i++){
        if(i > loopIndex && trase.at(i) == loop){
            break;
        }
        loop_rui.push_back(loop_rui.at(i-loopIndex)+trase.at(i));
        //cout << loop_rui.back() << endl;
    }
    ans += loop_rui.back()*(N/(loop_rui.size()-1))+loop_rui.at(N%(loop_rui.size()-1));
    cout << ans << endl;
}