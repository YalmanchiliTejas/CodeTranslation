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

int n,x;
int pat[51],total[51];

int eat(int ni, int xi){
    // cerr << ni << " " << xi << endl;
    int ret = 0;
    if (xi >= total[ni]) return pat[ni];
    if (ni == 0) return 0;
    
    if (xi <= 1) return 0;
    if (xi <= 1 + total[ni-1]) return eat(ni-1, xi-1);
    ret += pat[ni-1];
    xi -= 1 + total[ni-1];
    if (xi < 1) return ret;
    ret++;
    xi--;
    return ret + eat(ni-1,xi);
}

signed main(){
    I(n); I(x);
    pat[0] = 1;
    REPS(i,n) pat[i] = pat[i-1]*2 + 1;
    total[0] = 1;
    REPS(i,n) total[i] = total[i-1]*2 + 3;

    cout << eat(n,x) << endl;
}