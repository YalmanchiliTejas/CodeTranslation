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

void op(vi& a){
    REP(i,sz(a)) a[i]++;
    auto it = max_element(all(a));
    *it -= sz(a)+1;

}

signed main(){
    int n;
    vi a;
    I(n);
    a.resize(n);
    REP(i,n) I(a[i]);

    int ret = 0;

    auto maxi = max_element(all(a));
    while(*maxi >= 2*n){
        int rep = (*maxi - n) / n;
        *maxi -= rep*(n+1);
        REP(i,n) a[i] += rep;
        ret += rep;
        maxi = max_element(all(a));
    }

    while(*maxi > n-1){
        ret++;
        op(a);
        maxi = max_element(all(a));
    }

    cout << ret << endl;
}