#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 0
//#ifdef LOCAL
//#define DEBUG(s) cout << (s) << endl
//#define dump(x)  cerr << #x << " = " << (x) << endl
//#define BR cout << endl;
//#else
//#define DEBUG(s) do{}while(0)
//#define dump(x) do{}while(0)
//#define BR
//#endif


//改造
typedef long long int ll;
using namespace std;
#define INF (1 << 20)
#define INFl (ll)5e15
#define DEBUG 0 //デバッグする時1にしてね
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007
//ここから編集する
ll dp[1001][1001];
class Combination {

public:
    vector<ll> fact;

    Combination(int max_n) {
        //1 ~ n!までの階乗modを求める
        int n = max_n;
        vector<ll> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        this->fact = fact;
    }

    template<typename T>
    //templateをつかってみｔか
    ll pow(T x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x;
        if (y == 2) return (x * x) % MOD;
//        if (y % 2 == 1) return pow(x, y / 2) * pow(x, y / 2) % MOD;
        if (y % 2 == 1) return pow(pow(x, y / 2), 2) * x % MOD;
//        return pow(x, y / 2) * pow(x, y / 2) % MOD;
        return pow(pow(x, y / 2), 2) % MOD;
    }

    ll nCk(int n, int k) {
//        return (fact[n] * pow(fact[n-k],MOD-2) * pow(fact[k],MOD-2)) % MOD;
        return (((fact[n] * pow(fact[n - k], MOD - 2)) % MOD) * pow(fact[k], MOD - 2)) % MOD;
    }

    ll nPk(int n,int k){
        return fact[n] * pow(fact[n-k],MOD-2) % MOD;
    }


    ll extgcd(ll a, ll b, ll& x, ll& y) {
        ll d = a;
        if (b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        } else {
            x = 1;
            y = 0;
        }
        return d;
    }

    ll mod_inverse(ll a, ll m) {
        ll x, y;
        extgcd(a, m, x, y);
        return (m + x % m) % m;
    }

};

ll nPk[1001][1001] = {};
ll ipowf[1001][1001] = {};
ll ifac[1001] = {};

int main() {
    Combination com(1001);

    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    dp[0][0] = 1LL;

    rep(i,0,1001){
        rep(j,0,1001){
            nPk[i][j] = ipowf[i][j] = -1;
        }
        ifac[i] = -1;
    }
    for(int k = 0; k < N; k++){
        for(int n = 0; n <= N; n++){
            if(dp[k][n] == 0) continue;
            dp[k+1][n] += dp[k][n];
            dp[k+1][n] %= MOD;
            if(A <= k + 1 && k + 1 <= B){
                for(int x = C; x <= D; x++){
                    if(n + (k+1) * x > N) break;
                    ll add = dp[k][n];
                    if(nPk[n+(k+1)*x][(k+1)*x] == -1){
                        nPk[n+(k+1)*x][(k+1)*x] = com.nPk(n+(k+1)*x,(k+1)*x);
                    }
                    add *= nPk[n+(k+1)*x][(k+1)*x];
                    add %= MOD;

                    if(ipowf[k+1][x] == -1){
                        ipowf[k+1][x] = com.pow(com.mod_inverse(com.fact[(k+1)],MOD),x);
                    }
                    add *= ipowf[k+1][x];
                    add %= MOD;

                    if(ifac[x] == -1){
                        ifac[x] = com.mod_inverse(com.fact[x],MOD);
                    }
                    add *= ifac[x];
                    add %= MOD;
                    dp[k+1][n + (k+1) * x] += add;
                    dp[k+1][n + (k+1) * x] %= MOD;
                }
            }
        }
    }

    cout << dp[N][N] << endl;
    return 0;
}
