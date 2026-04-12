#include<bits/stdc++.h>

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
#define FOR_ITER(x, a) for(auto x = a.begin(); x != a.end(); ++x)

#define pb push_back
#define pf push_front
#define mp make_pair
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)FOR_ITER
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define VL vector<long long>
#define F first
#define S second

using namespace std;


typedef complex<double> P;
typedef unsigned char byte;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
inline int gcd(int a, int b) {
    if (b == 0) return a;
    return a < b? gcd(b, a) : gcd(b, a % b);
}
ll mo=1000000007;
const ll INF = 1e18;

bool f(pll p1, pll p2) {
    return p1.fi < p2.fi;
}


class Node {
public:
    bool isVisited;
    int idx;
    vector<int> nbs;
    Node(int id, bool flag): idx(id), isVisited(flag) {
    }
};

int cnt = 0;
vector<Node> vct;

void visit(Node &node, int ord, int n) {
    if (ord == n) {
        cnt++;
        return;
    }

    node.isVisited = true;
    vector<int> &nbs = node.nbs;
    for(int i: nbs) {
        Node &nb = vct.at(i - 1);
        if (!nb.isVisited) {
            visit(nb, ord + 1, n);
        }
    }
    node.isVisited = false;
}

int main(){
    int n, m;
    cin >> n >> m;


    FO(i, n) {
        vct.pb(Node(i + 1, false));
    }

    FO(i, m) {
        int a, b;
        cin >> a >> b;
        vct.at(a - 1).nbs.pb(b);
        vct.at(b - 1).nbs.pb(a);
    }

    visit(vct.at(0), 1, n);

//    FO(i, n) {
//        Node &node = vct.at(i);
//        cout << node.idx << ": ";
//        FOR_ITER(it, node.nbs){
//            cout << *it << " ";
//        }
//        cout << endl;
//    }

    cout << cnt << endl;
    return 0;
}


/**

#include <bits/stdc++.h>
//#include <fcntl.h>

using std::max; using std::swap; using std::abs; using std::priority_queue; using std::queue; using std::bitset; using std::make_tuple;
using std::istream; using std::ostream; using std::fixed; using std::greater; using std::tuple; using std::tie; using std::make_pair;
using std::cout; using std::cerr; using std::endl; using std::lower_bound; using std::upper_bound; using std::deque; using std::min;
using std::map; using std::string; using std::fill; using std::copy; using std::sort; using std::unique; using std::unordered_set;
using std::multiset; using std::nth_element; using std::min_element; using std::max_element; using std::vector; using std::set;
using std::unordered_map; using std::pair; using std::next_permutation; using std::reverse; using std::rotate; using std::cin;
using std::iota; using std::function; using std::shuffle; using std::iter_swap;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

int const INF = 100 + (int) 1e9;
ll const INFL = 100 + (ll) 1e18;
ld const PI = 3.141592653589793238462643L;
std::mt19937 mt19937(960172);

ll rnd(ll x, ll y) { static auto gen = std::bind(std::uniform_int_distribution<ll>(), mt19937); return gen() % (y - x + 1) + x; }
bool is_prime(ll x) { if (x <= 1) return 0; for (ll y = 2; y * y <= x; ++y) if (x % y == 0) return 0; return 1; }
ll sqr(int a) { return (ll) a * a; } ld sqr(ld a) { return a * a; } ll sqr(ll a) { return a * a; }
ll gcd(ll a, ll b) { while (b > 0) { ll t = a % b; a = b; b = t; } return a; }




void solve() {

    int n;
    cin >> n;

    ll a = 1, b = 1;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;

        ll c1 = (a + x - 1) / x;
        ll c2 = (b + y - 1) / y;
        ll c = max(c1, c2);
        a = x * c;
        b = y * c;
    }

    cout << a + b << '\n';
}



int main() {

    //freopen("", "r", stdin);
    //freopen("", "w", stdout);

    cout.precision(15);
    cout << fixed;
    cerr.precision(6);
    cerr << fixed;

    int tcn = 1;
    for (int tn = 1; tn <= tcn; ++tn)
        solve();

#ifdef LOCAL
    cerr << "time: " << (ll) clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
#endif
}

*/
