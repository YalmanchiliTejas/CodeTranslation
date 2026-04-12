///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///



///   ***   ---   |||   Author : Muhammad Shahriar Alam   |||   ---   ***   ///
///   ***   ---   |||     Student : CSE, CU, 3rd Year     |||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;



///   ***   ---   |||   Template   |||   ---   ***   ///



typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mx_int_prime 999999937

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
///#define harmonic(n) 0.57721566490153286l+log(n)

#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

///bit


///to_s


int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};


///mod

///seive


///debug
template < typename F, typename S > ostream& operator << ( ostream& os, const pair< F, S > & p ) {return os << "(" << p.first << ", " << p.second << ")";}
template < typename T >ostream &operator << ( ostream & os, const vector< T > &v ) {os << "{";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "}";}
template < typename T >ostream &operator << ( ostream & os, const set< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename T >ostream &operator << ( ostream & os, const multiset< T > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << *it;}return os << "]";}
template < typename F, typename S >ostream &operator << ( ostream & os, const map< F, S > &v ) {os << "[";for(auto it = v.begin(); it != v.end(); ++it) {if( it != v.begin() ) os << ", ";os << it -> first << " = " << it -> second ;}return os << "]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T> void faltu( T a[], int n ) { for(int i = 0; i < n; ++i) cerr << a[i] << ' ';cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}



///   ***   ---   |||   Source Code   |||   ---   ***   ///

const int mx = 3e3+123;
ll dp[mx][mx][3], a[mx];

ll solve ( int i, int j, int f1 )
{
    if ( i > j ) return 0;
    if ( dp[i][j][f1] != -1 ) return dp[i][j][f1];

    ll ret = 0;
    if ( f1 == 0 ) {
        ret = max ( a[i] + solve ( i+1, j, !f1 ), a[j] + solve ( i, j-1, !f1 ) );
    }
    else {
        ret = min (  solve ( i+1, j, !f1 ), solve ( i, j-1, !f1 ) );
    }

    return dp[i][j][f1] = ret;
}


int main()
{
    optimize();

    mem (dp, -1);

    int n;
    ll sum = 0;

    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        sum += a[i];
    }

    ll x = solve ( 1, n, 0 );
    ll y = sum - x;

    cout << x - y;

    return 0;
}
















