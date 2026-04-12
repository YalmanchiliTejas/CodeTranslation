#define TEST_MODE false

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep2(i, a, b) for (int i = (a)-1; i >= b; --i)
#define range(i, a, b, c) for (int i = a;             \
                               c > 0 ? i < b : i > b; \
                               i += c)
#define chmax(a, b) (a = (a) < (b) ? (b) : (a))
#define chmin(a, b) (a = (a) > (b) ? (b) : (a))
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) begin(a), end(a)
#define ifnot(a) if (not(a))
#define int long long

#ifdef LOCAL_ENV

#if TEST_MODE == true
const bool test = true;
#define dump(x) cerr << #x << " = " << (x) << endl
#else
const bool test = false;
#define dump(x) 
#endif

#else
const bool test = false;
#define dump(x) 
#endif

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int INF = (int)1 << 60;
const ll INFL = (ll)1 << 60;
ll mod_n = (int)1e9 + 7;
const double eps = 1e-10;
typedef long double Real;
// return -1, 0, 1
int sgn(const Real &r) { return (r > eps) - (r < -eps); }
int sgn(const Real &a, const Real &b) { return sgn(a - b); }

//.....................
const int MAX = (int)2e5 + 5;

vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, sep))
    {
        v.push_back(buffer);
    }
    return v;
}

template <class InputIterator>
int sum(InputIterator begin, InputIterator end)
{
    return accumulate(begin, end, 0ll);
}

void solve();

class Solver {
public:
    int n;
    int a[200005];
    int res[200005];

    void solve() {
        cin >> n;
        rep(i, n) cin >> a[i];
        rep(i, n/2 + n%2) res[i] = a[(n/2 + n%2)*2-2-i*2];
        rep2(i, n/2 + n%2, n) res[i] = a[(i-(n/2 + n%2))*2 + 1];
        if (n % 2 == 0) {
            reverse(res, res + n);
        }
        rep(i, n) {
            cout << res[i] << " ";
        } 
        cout << endl;
    }
};

signed main()
{
    cout << fixed << setprecision(20);
    auto ptr = new Solver();
    ptr->solve();
    delete ptr;
    // while (true) {    
    //     auto ptr = new Solver();
    //     ptr->solve();
    //     delete ptr;
    // }
    return 0;
}

// class Mycin {
// 	bool flag = true;
// public:
// 	Mycin& operator >> (int& a) {flag = scanf("%lld", &a) != EOF; return *this;}
// 	Mycin& operator >> (char& a) {flag = scanf("%c", &a) != EOF; return *this;}
// 	Mycin& operator >> (string& s) {flag = (bool)(cin >> s); return *this;}
// 	operator bool() {return flag;}
// } mycin;
 
// class Mycout {
// public:
// 	Mycout& operator << (const int& a) {printf("%lld", a); return *this;}
// 	Mycout& operator << (const char c) {printf("%c", c); return *this;}
// 	Mycout& operator << (const string& s) {printf("%s", s.c_str()); return *this;}
// } mycout;
 
// #define cin mycin
// #define cout mycout
// #define endl '\n'


