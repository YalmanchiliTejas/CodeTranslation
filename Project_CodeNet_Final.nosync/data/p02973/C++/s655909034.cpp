#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout <<"DEBUG"<<" "<< #x << ":" << x << '\n'

//↓0-originか1-originでn回繰り返し
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   //0-origin昇順
#define rep1(i,n) for(int i = 1; i <= ((int)(n)); i++) //1-origin昇順
#define rrep(i,n) for(int i = ((int)(n)-1); i >= 0; i--)  //0-origin降順
#define rrep1(i,n) for(int i = ((int)(n)); i >= 1; i--)   //1-origin降順
//rep2 -> 第二引数 m から n 回繰り返し ex) m=5 n=3 なら i=5,i=6,i=7 まで
#define rep2(i,m,n) for(int i = ((int)(m)); i < ((int)(n))+((int)(m)); i++)
#define SIZE(x) ((int)((x).size()))
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vii; //2次元配列
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> PII;
template<class T,class U> inline bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U> inline bool chmin(T &a, const U &b){if(a>b){a=b;return 1;}return 0;}

/* 円周率は M_PI を使おうね */
const ll infll = (1LL<<62)-1;
const int inf = (1<<30)-1;
int mod = 1000000007;

/*FUNCs=================================================*/
#include <bits/stdc++.h>
using namespace std;

/*最長増加or減少部分列----------*/
/*第一引数 : 対象となるvector
  第二引数 : true:狭義 false:広義  デフォルト:0
  第三引数 : true:増加 false:減少  デフォルト:1
*/
template<class T>
std::vector<T> lis(const vector<T> &a, bool strict=0, bool UporNot=1) {
    std::vector<T> lis;
    if(UporNot) {
        for(auto &p : a) {
            typename std::vector<T>::iterator iter;
            //using iter = std::vector<T>::iterator;
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
            //using iter = std::vector<T>::iterator;
            if(strict) iter = std::lower_bound(lis.begin(), lis.end(), p);
            else iter = std::upper_bound(lis.begin(), lis.end(), p);
            if(lis.end()==iter) lis.emplace_back(p);
            else *iter = p;
        }
    }
    return lis;
}

/*------------------------------*/

/*MAIN==================================================*/
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);   //cin cout 高速化
    //cout << fixed << setprecision(10);

    int n; cin >> n;
    vi a(n); rep(i,n) cin >> a[i];
    vi ret = lis(a, 0, 0);
    cout << ret.size() << '\n';
}
