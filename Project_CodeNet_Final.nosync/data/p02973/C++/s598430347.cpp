#include<algorithm>
#include<algorithm>     //sort,二分探索,など
#include<bitset>        //固定長bit集合
#include<cmath>         //pow,logなど
#include<complex>       //複素数
#include<deque>         //両端アクセスのキュー
#include<functional>    //sortのgreater
#include<iomanip>       //setprecision(浮動小数点の出力の誤差)
#include<iostream>      //入出力
#include<iterator>      //集合演算(積集合,和集合,差集合など)
#include<map>           //map(辞書)
#include<numeric>       //iota(整数列の生成),gcdとlcm(c++17)
#include<queue>         //キュー
#include<set>           //集合
#include<stack>         //スタック
#include<string>        //文字列
#include<unordered_map> //イテレータあるけど順序保持しないmap
#include<unordered_set> //イテレータあるけど順序保持しないset
#include<utility>       //pair
#include<vector>        //可変長配列

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;
const ll MOD = 1000000007;
const ll INF = 1000000000000000000;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vi A(N);
    rep(i, N) cin >> A[i];
    reverse(all(A));

    map<int, int> m;

    for(auto a : A)
    {
        auto itr = m.upper_bound(a);

        if (itr != m.end())
        {
            (*itr).second--;
            if ((*itr).second == 0) m.erase(itr);
        }

        m[a]++;
    }

    ll count = 0;
    for (auto x : m) count += x.second;

    cout << count << endl;

    return 0;
}