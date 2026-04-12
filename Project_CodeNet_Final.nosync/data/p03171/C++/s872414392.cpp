//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
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

    const int mod = 1000000007;

//--------------------------------------------

int n,a[3010];
int dp[3010][3010];

int taro(int l, int r){
    if (r-l <= 0) return 0;
    if (r-l == 1) return a[l];
    if (dp[l][r] < (1LL << 60)) return dp[l][r];
    int ltake = a[l];
    ltake += min( -a[l+1] + taro(l+2,r), -a[r-1] + taro(l+1, r-1));
    int rtake = a[r-1];
    rtake += min( -a[l] + taro(l+1,r-1), -a[r-2] + taro(l,r-2));

    return dp[l][r] = max(ltake, rtake);
}

signed main(){
    I(n);
    REP(i,n) I(a[i]);
    REP(i,n+1) REP(j,n+1) dp[i][j] = (1LL << 60);
    cout << taro(0,n) << endl;
}