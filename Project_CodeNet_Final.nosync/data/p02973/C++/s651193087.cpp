#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout <<"DEBUG"<<" "<< #x << ":" << x << '\n'

// n回繰り返し
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
#define rep1(i,n) for(int i = 1; i <= ((int)(n)); i++) // 1-indexed昇順
#define rrep(i,n) for(int i = ((int)(n)-1); i >= 0; i--)  // 0-indexed降順
#define rrep1(i,n) for(int i = ((int)(n)); i >= 1; i--)   // 1-indexed降順
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vii;  // 2次元配列
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> PII;

template<typename T>
using vec = vector<T>;
template<class T>
using maxheap = std::priority_queue<T>;
template<class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T,class U> inline bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U> inline bool chmin(T &a, const U &b){if(a>b){a=b;return 1;}return 0;}

const ld Pi = std::acos(-1.0L);
const ll infll = (1LL<<62)-1;
const int inf = (1<<30)-1;
const int mod = 1000000007;
// const int mod = 998244353;

/*最長増加or減少部分列----------*/
/*第一引数 : 対象となるvector
  第二引数 : true:狭義 false:広義  デフォルト:false
  第三引数 : true:増加 false:減少  デフォルト:true
*/
template<class T>
std::vector<T> lis(const std::vector<T> &a, bool strict=0, bool UporNot=1) {
    std::vector<T> lis;
    if(UporNot) {
        for(auto &p : a) {
            typename std::vector<T>::iterator iter;
            if(strict) iter = std::lower_bound(lis.begin(), lis.end(), p);
            else iter = std::upper_bound(lis.begin(), lis.end(), p);
            if(lis.end()==iter) lis.emplace_back(p);
            else *iter = p;
        }
    }else {
        vector<T> rev = a;
        reverse(rev.begin(), rev.end());
        for(auto &p : rev) {
            typename std::vector<T>::iterator iter;
            if(strict) iter = std::lower_bound(lis.begin(), lis.end(), p);
            else iter = std::upper_bound(lis.begin(), lis.end(), p);
            if(lis.end()==iter) lis.emplace_back(p);
            else *iter = p;
        }
    }
    return lis;
}

/*FUNCs=================================================*/


/*MAIN==================================================*/
signed main(){
    int _StartTime_ = clock();
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   //cin cout 高速化
    // cout << fixed << setprecision(15);

    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];

    /*
     * 同じ色のグループは増加部分列を形成する
     * ではそれらのグループの後端となる数の位置はどうあるべきか
     * これは数列の後ろの方にいるほど長い増加部分列の後端になっている方がいい
     * よって後ろから最長増加部分列をとると各増加部分列の後端の数を数えられる
     */

    vi l = lis(a, 0, 0);
    cout << l.size() << '\n';

    // printf("ExecutionTime: %d /ms\n",1000*(int)((clock()-_StartTime_)/CLOCKS_PER_SEC));
}