// だーれだ？
//qqqqqqHHMqqqqqHf!(:;jHmmkf``(:;jkqqqqqqqqqmMH#HMqqK_````````````````(kqqqqqqHMMM
//qqqqqqHHmqqqqH=` :;;jkqH=?~..;;jqqqqqqqqqmM#HM#MHH!```` ```````..-``dqWbWkRqHMMM
//qqqqqqMHmqqqK!``.;;;dqH: ```.?TUqqHmqqqqmHHHM4Mqkt..```` ..JgHHW@P`.HHkqHHHqM#NN
//qqqqqmHMmqHTYWHgHmmgHR...``` :;Jkq9qqqqqgMH#1dHk$...-gW@HY"=!``dH! dHNmqqqqmM###
//qqqqqqgMmH[````` ?dHMMMHHHHHJ<;JkK>XqqqmMH#<+Hb%.WYYTHppf-````.gt`.HHMmmqqqmM###
//qqkqqqm@H?S,```` Jpbbpp:```` :!dK<;JkqqMMY(;dW^````.ppbpf!```.Y<`.HHHMgmqqqmH###
//qqqqqqqqD`` ````(ppbppW````` ~.f`:;jkqM#^.;jf!````.Wppbpf````````(HH#HmmqqmH#NN#
//qqqqqqqkP``````.fpbpbpf``` ` `.``~:;WHY``(+=``````Jppbpf\```` ``.MH#HHgqqqmHNNNN
//qqqqqqqk]```` `,fpbbpf>```` `` ``_:<? ``.?!``` `` Wpppp%``` ``` dHH##HmmqqmH####
//qqqqqqqk]``````,fpbppt``` `` `` `_~````` `` `` ```WppW=``` ````.HHHHMHmmqqmM####
//qqqqqqqk$`` ````4ppfY```` `` `` `- `` `` `` ``` ``(T=`````` ``.MH##HMMmmqqmM##HH
//qqqqqqHqP``` ````?7!```` `` `` ``` `` ` ` ``  ````````` ` ````.MHH#HgMmqmqmHHHHH
//qqqkqqmkR```` `        `` ` `` ` ` ` ``` ` ``` `   ......_. ```dH#HHgMqqgqqmH#HH
//NqqqqqHqR```  _ ........_` `` ``` ``` ````` ``` ............```,HHHHmqqqHqqmMH##
//MmqqqqHqR```  _........_ `` `` ``` `` `  `` ` ` `  `__     ` ``,HHHMmmqqMHmmMHH#
//HMqqqqXkH `````````````` ` `` `  `` `` `` `` `` ```` ````` ````.HHHMmMHm@HHqmMHH
//HHHmqqfHk;``` `  ` `` ` ` `` ``` ` ` ``` `` `` `` ````  `..```.HHHHMMHMg@HHHHHMH
//HHMmmqMHkP<.`` ``` ` ` ``` `` ``` ``` ` `` `` `` `  ````  ```.MH##HM#HMg@@@@H@HH
//##HNmqR`jW<<_ ``` ````` `` ` ` ``` `` `` `` `` ````  ````` .dHH##H#HHHMHH@@H@@@@
//HH##NqH..X2:<<-.`` ` `` ``` ``` ` `` `` `` ` `` ` ``` ` .gMHHH#H#HHH#HM@@H@@H@@H
//-WHHHNH[ =v._:::<-. ` `` ` ``  ```````.`` `````````     .MHH###H#MHHHHH@H@H@@HH@
//` 7MHHMH.l==.  ~:::::<_-.. ````` ``````` ``  ...uX;     `,MHHHH#M@@MM@@@@@@H@@@@
//  . TMHHbZl=1.   _~::::::(<::<:<___-___:<<:::::jX3=. ` ` `,MMHM@@@@Mg@@@@@@@@@H@
//
#include <bits/stdc++.h>
#define int long long
#define ll long long 
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define fore(i, x, a) for(auto &&x:a) 
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define pb push_back
#define mp make_pair
#define ALL(x) begin(x),end(x)
#define F first
#define S second
#define debug(x)  cout << #x << ": " << (x) << '\n';
const long long INF=1001001001001001001;
const int MOD=(int)1e9 + 7;
const double EPS=1e-9;
using namespace std;
using Pii = pair<int,int>;
using vii = vector<int>;
template<class T>using  PS_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){fill( (T*)array, (T*)(array+N), val );}
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct edge { int from, to, cost; };
int dy[]={0, 1, -1, 0}; int dx[]={1, 0, 0, -1};
// cout << fixed;
// cout << setprecision(10) << val;

int n;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
  cin >> n;
  vii a(n), ans;
  cin >> a;

  if (n % 2) {
    for (int i = n-1; i >= 0; i -= 2) ans.pb(a[i]);
    for (int i = 1; i < n; i += 2) ans.pb(a[i]);
  } else {
    for (int i = n-1; i >= 0; i -= 2) ans.pb(a[i]);
    for (int i = 0; i < n; i += 2) ans.pb(a[i]);
  }
  cout << ans << endl;
  return 0;
}

