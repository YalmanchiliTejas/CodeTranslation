#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

LL powmod(LL x, LL y){ // pow(x,y)
    if(y == 0) return 1;
    if(y == 1) return x;

    if(y%2 == 0){
        return powmod(x,y/2) * powmod(x,y/2) % MOD;
    }
    else{
        return powmod(x,y-1) * x % MOD;
    }
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    COMinit();

    int N,M,K; cin >> N >> M >> K;
    LL ans = 0;

    for(LL i = 0; i < N; i++){
        LL wa = (N-i) * (N-i-1) / 2;
        dump(wa)
        ans = (ans + wa * M % MOD * M % MOD * COM(N*M-2, K-2) % MOD) % MOD;
    }
    for(LL i = 0; i < M; i++){
        LL wa = (M-i) * (M-i-1) / 2;
        ans = (ans + wa * N % MOD * N % MOD * COM(N*M-2,K-2) % MOD) % MOD;
    }
    cout << ans << endl;




}
