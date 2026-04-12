/// Containers Start
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include<random>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
/// Containers End


using namespace std;


/// Math Start
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define EPS (1e-7)
#define INF (0x3f3f3f3f)
/// Math End


/// Extra Start
#define nn                    '\n'
#define pb                    push_back
#define SS                    stringstream
#define ull                   unsigned long long
#define mod                   1000000007
#define SIZE                  2000001
#define _cin                  ios_base::sync_with_stdio(0);  cin.tie(0);
#define sz(a)                 int((a).size())
#define space                 " "
#define All(x)                (x).begin(), (x).end()
#define rall(x)               (x).rbegin(), (x).rend()
#define Ignore                cin.ignore()
#define StringToInt           if ( ! (istringstream(s) >> n) ) n = 0;
#define SORT(c) sort(All((c)))
#define RSORT(c) sort(rall((c)))
/// Extra End


/// Functions Start
template<class T>
T gcd(T a, T b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

template<class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<class T>
string converter(T n) {
    SS x;
    x << n;
    return x.str();
}

#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define FORA(arr) for(auto &i:arr)
#define Cin(a)     cin >>a;
#define Cin2(a, b)        cin>>a>>b;
#define Cin3(a, b, c)        cin>>a>>b>>c;
#define Cin4(a, b, c, d)   cin>>a>>b>>c>>d;
#define Cini(a)        int a; cin>>a;
#define Cinii(a, b)        int a,b; cin>>a>>b;
#define Cins(s)         string s; cin >> s;
#define Cinc(c)         char c; cin >> c;
/// Functions End


/// Array Start
#define SET(a)                memset( a, -1,    sizeof a )
#define CLR(a)                memset( a,  0,    sizeof a )
#define MEM(a, val)            memset( a,  val,  sizeof a )
/// Array End


/// Debug Start
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define deb3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << end
/// Debug End


/// TypeDef Start
typedef long long int ll;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<int, string> mis;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<pii> vii;
/// TypeDef End

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/


///topcoder template

int d[10][10];
int ans = 0;
int n, m;


void dfs(int *cc, int i) {
    cc[i] += 1;
    int c[n];
    copy(cc, cc + n, c);
    rep(k, n) {
        if (d[i][k] == 1 && c[k] == 0) {
            int newc[n];
            copy(c,c+n,newc);
            dfs(newc, k);
        } else {
            int sumi = 0;
            rep(j, n) sumi += c[j];
            if (sumi == n) {
                ans += 1;
                return;
            }
        }
    }
}

int main(void) {

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    Cin2(n, m);
    int a[m], b[m];
    rep(i, m) cin >> a[i] >> b[i];

    MEM(d, 0);
    rep(i, m) {
        d[a[i] - 1][b[i] - 1] += 1;
        d[b[i] - 1][a[i] - 1] += 1;
    }

    int c[n];
    MEM(c, 0);
    dfs(c, 0);
    cout << ans << endl;


    return 0;

}



