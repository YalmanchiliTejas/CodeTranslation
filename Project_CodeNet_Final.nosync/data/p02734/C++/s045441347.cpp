//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #ifdef ONLINE_JUDGE
        #pragma GCC target ("avx512f")
    #else
        #pragma GCC target ("avx")
    #endif
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 998244353;

//--------------------------------------------

int n,s;
int a[3000];
int dp[3001][6001];

signed main(){
    I(n); I(s);
    REP(i,n) I(a[i]);
    dp[0][0] = 1;
    REPS(i,n){
        dp[i][0]++;
        REP(j,s+1){
            dp[i][j] += dp[i-1][j];
            dp[i][j + a[i-1]] += dp[i-1][j];
        }
        REP(j,s+1) dp[i][j] %= mod;
    }
    int ret = 0;
    REPS(i,n) ret = (ret + dp[i][s]) % mod;
    cout << ret << endl;
}