/*
 *  TEMPLATE BY LOUIS NAVARRO
 *  FREE OF USE
 *  (inspired by other templates)
*/
#include <bits/stdc++.h>

using namespace std;

/*
 *
 * TYPE DEFINITIONS
 *
 */
// Basic types
#define uint unsigned int
#define ull unsigned long long
#define ll long long
#define ld long double
// Vectors
#define vt vector
#define vti vector<int>
#define vtl vector<long long>
#define vtd vector<double>
#define vtld vector<long double>
// Maps
#define mmap multimap
#define umap unordered_map
#define mii map<int, int>
#define mmii multimap<int, int>
#define umii unordered_map<int, int>
// Sets
#define mset multiset
#define uset unordered_set
#define umset unordered_multiset
// Array
#define ar array

/*
 *
 * FUNCTIONS / METHODS DEFINITIONS
 *
 */
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SET(a, v) memset(a, v, sizeof(a))

/*
 *
 * LOOPS
 *
 */
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define F(...)         \
    F_ORC(__VA_ARGS__) \
    (__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)


/*
 *
 * MATH
 *
 */

// VARIABLES
const double PI = acos(-1);
const double Pi = 3.141592653589793;

const ll MOD = 1e9+7;
const ll FMOD = 998244353;

// FUNCTIONS
// Binary exponentation
ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0)
    {
        res *= a * (ll)(b & 1LL);
        a *= a;
        b /= 2;
    }
    return res;
}

// Binary search
template <class T, class S>
int search(T a, S el, int n = 0){
    n = n ? n : a.size();
    int i = 0;
    for (int b = n / 2; b > 0; b /= 2)
        while (i + b < n && a[i] <= el)
            i += b;
    return i;
}

// Comparisions
template <class T> bool umin(T &a, const T &b){
    return a > b ? a = b, 1 : 0;
}
template <class T> bool umax(T &a, const T &b){
    return a < b ? a = b, 1 : 0;
}

// GCD / LCM
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int lcm(int a, int b){
    return a * b / gcd(a, b);
}
int egcd(int a, int b, int& x, int& y){
    if (b==0){
        x=1;
        y=0;
        return a;
    }
    int x1, y1;
    int d=egcd(b, a%b, x1, y1);
    x=y1;
    y=x1 - y1*(a/b);
    return d;
}


/*
 *
 * INPUT / OUTPUT
 *
 */

// Reading (input)
template <class A>
void read(vt<A> &v);
template <class A, size_t S>
void read(ar<A, S> &a);
template <class T>
void read(T &x){
    cin >> x;
}
void read(double &d){
    string t;
    read(t);
    d = stod(t);
}
void read(float &d){
    string t;
    read(t);
    d = stod(t);
}
void read(long double &d){
    string t;
    read(t);
    d = stold(t);
}
template <class H, class... T>
void read(H &h, T &... t){
    read(h);
    read(t...);
}
template <class A>
void read(vt<A> &x){
    EACH(a, x)
        read(a);
}
template <class A, size_t S>
void read(array<A, S> &x){
    EACH(a, x)
        read(a);
}

// Type casting (for writing)
string to_string(char c){
    return string(1, c);
}
string to_string(bool b){
    return b ? "true" : "false";
}
string to_string(const char *s){
    return string(s);
}
string to_string(string s){
    return s;
}
string to_string(vt<bool> v){
    string res;
    F(sz(v))
        res += char('0' + v[i]);
    return res;
}

template <size_t S>
string to_string(bitset<S> b){
    string res;
    F(S)
        res += char('0' + b[i]);
    return res;
}
template <class T>
string to_string(T v){
    bool f = 1;
    string res;
    EACH(x, v)
    {
        if (!f)
            res += ' ';
        f = 0;
        res += to_string(x);
    }
    return res;
}

// Writing (output)
template <class A>
void write(A x){
    cout << to_string(x);
}
template <class H, class... T>
void write(const H &h, const T &... t){
    write(h);
    write(t...);
}
// Printing (output + "\n")
void print(){
    write("\n");
}
template <class H, class... T>
void print(const H &h, const T &... t){
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

void DBG(){
    cerr << "]" << endl;
}
template <class H, class... T>
void DBG(H h, T... t){
    cerr << to_string(h);
    if (sizeof...(t))
        cerr << ", ";
    DBG(t...);
}

#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)

/*
 *
 * CONSTANTS
 *
 */
//const int INF = 2147483647;
const int INF = 1e9;

const ll mxN = 1e9;

/*
 *
 * CODE HERE
 *
 */
void solve(){
    int n;
    read(n);
    vt<ll> a(n);
    read(a);
    //int ans=0;
    //F(n-1)
        //F(j, i+1, n)
            //ans = (ans+(a[i]*a[j])%MOD)%MOD;
    //print(ans);

    vt<ll> ss(n);
    ll cur=0;
    F(i, n-1, -1, -1){
        cur=(a[i]+cur)%MOD;
        ss[i]=cur;
    }
    ll ans=0;
    F(n-1)
        ans = (ss[i+1]*a[i]%MOD+ans) % MOD;
    print(ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
        
    int t = 1;
    //read(t);
    F(t){
        //write("Case #",  i+1, ": ");
        solve();
    }
}
