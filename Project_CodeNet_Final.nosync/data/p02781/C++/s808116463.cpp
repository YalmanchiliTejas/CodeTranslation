#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n) for(int i = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int i = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int i = (int)(a);(x);++(i))
#define repr(i, a, n) for(int i = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int i = (int)(a);(i) >= (int)(n);--(i))
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RNG(x, a, n) begin(x)+(a), begin(x)+(n)
#define ADD(a, b) ((((a)%MOD+MOD)%MOD+((b)%MOD+MOD)%MOD)%MOD)
#define SUB(a, b) ((((a)%MOD+MOD)%MOD-((b)%MOD+MOD)%MOD+MOD)%MOD)
#define MUL(a, b) (((((a)%MOD+MOD)%MOD)*(((b)%MOD+MOD)%MOD))%MOD)
#define CHADD(a, b) (a = ADD(a, b))
#define CHMUL(a, b) (a = MUL(a, b))
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define gcd(x, y) __gcd(x,  y)
#define lcm(x, y) ((x)/gcd(x,y)*(y))
#define isin(x, l, r) ((l) <= (x) and (x) < (r))
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define PI (acos(-1))
#define EPS (1e-10)
#define INF LLONG_MAX
#define MOD 1000000007LL
using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;
using TIII = tuple<int, int, int>;
using VPII = vector<PII>;
using VTIII = vector<TIII>;
using Complex = complex<double>;
template<typename T, template<typename> typename C = less> using PQ = priority_queue<T, vector<T>, C<T>>;
template<typename T> bool chmax(T& a, const T& b){ if(a<b){ a=b; return true; } return false; }
template<typename T> bool chmin(T& a, const T& b){ if(a>b){ a=b; return true; } return false; }


string N;
int K;
int dp[110][2][10];


signed main(){
    cin >> N >> K;

    dp[0][1][0] = 1;
    rep(i, 0, SZ(N)) rep(j, 0, 2) repe(k, 0, K){
        int x = j ? N[i]-'0' : 9;
        repe(r, 0, x) dp[i+1][j and r == x][k+(!!r)] += dp[i][j][k];
    }

    cout << dp[SZ(N)][0][K]+dp[SZ(N)][1][K] << endl;

    return 0;
}