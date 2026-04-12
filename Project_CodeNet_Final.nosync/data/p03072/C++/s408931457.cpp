#include <bits/stdc++.h>
using namespace std;

//type
#define ll long long
typedef pair<int, int> P;
//定数
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007    //10^9+7:合同式の法
#define MAXR 100000       //10^5:配列の最大のrange
//略記
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
#define F first      //pairの一つ目の要素
#define S second     //pairの二つ目の要素
#define Z class
// OTHER
// xの二乗を返す (関数テンプレート版)
template <typename T>
T square(T x) { return x * x; }
template <class T>
T GCD(T a, T b)
{
    T r;
    while (a)
        r = b, b = a, a = r % a;
    return b;
}
template <class T>
T LCM(T a, T b) { return a / GCD(a, b) * b; }

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))
// loop
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repe(i, n) for (ll i = 0; i <= (n); i++)
#define repd(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (b); i--)
#define FORA(i, I) for (const auto &i : I)

// vector
#define ALL(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ll> vl;
#define ERASE(x) x.erase(unique(ALL(x)), x.end()); // erase same elements
#define VEC(type, c, n)     \
    std::vector<type> c(n); \
    for (auto &i : c)       \
        std::cin >> i;

// input
#define INIT                          \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);
#define VAR(type, ...) \
    type __VA_ARGS__;  \
    MACRO_VAR_Scan(__VA_ARGS__);
template <typename T>
void MACRO_VAR_Scan(T &t)
{
    std::cin >> t;
}
template <typename First, typename... Rest>
void MACRO_VAR_Scan(First &first, Rest &... rest)
{
    std::cin >> first;
    MACRO_VAR_Scan(rest...);
}

// output
template <typename T>
void MACRO_OUT(const T t) { std::cout << t; }

#define OUT(...) MACRO_OUT(__VA_ARGS__);
#define SP std::cout << " ";
#define TAB std::cout << "\t";
#define BR std::cout << "\n";
#define ENDL std::cout << std::endl;

#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define yes() printf("yes\n")
#define no() printf("no\n")
#define ln cout << '\n'
template <Z A>
void pr(A a)
{
    cout << a;
    ln;
}
template <Z A, Z B>
void pr(A a, B b)
{
    cout << a << ' ';
}

ll ans = 0;
bool check = 0;
bool boo = 0;
string s, t;
int N = 3;
vector<int> v(N);
int a, b, c, d, n, m = 0;
int x = 0, y = 0;
int sum;
char ch;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// cout << (conditon ? (result:  == 1 ): (==0)) << endl; <- output result of if
// long long 型が表せる値の上限はおよそ 9 × 10＾18 です．
int main()
{
    INIT;
    cin >> n;
    rep(i, n)
    {
        cin >> a;
        if (m <= a)
            ans++;
        m = max(m, a);
    }
    pr(ans);

    return 0;
}
