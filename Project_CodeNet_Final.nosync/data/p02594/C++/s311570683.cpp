#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI 3.14159265358979323846264338327950L

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define PB push_back

template<typename T, typename U, typename Comp=less<>>
bool chmax(T& xmax, const U& x, Comp comp={}) {
    if(comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b){
    if(a % b == 0){
        return(b);
    }
    else{
        return(gcd(b, a % b));
    }
}

bool isPalindrome(string s){
    REP(i, s.length() / 2){
        if(s[i] != s[(s.length() - 1) - i]){
            return false;
        }
    }
    return true;
}

//scanf("%lld", &);
//cin >> ;
//cout << ans << endl;

int N, M, i, j, k, l, tmp, ans, L, p, now_count;

int main(){
    cin >> N;

    if (N >= 30){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    //cout << ans << endl;
    return 0;
}