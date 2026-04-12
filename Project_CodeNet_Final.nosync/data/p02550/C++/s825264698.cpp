//g++ t.cpp -o t && t < p.txt
//d>p.txt&&t<p.txt&&t2<p.txt

#include <iostream> // プログラムの耳と口
#include <vector> // 超有能配列秘書
#include <algorithm> // みんな大好きソートと二分探索
#include <queue> // きゅーちゃん、だいすき
#include <string> // to_string
#include <functional> // 関数を変数に入れる子
#include <set> // 値の取得・挿入・削除を高速に
#include <map> // setの妹 これまた優秀
#include <random> // 乱択さん
#include <ctime>
#include <bitset>

#define DB cerr<<"D"<<endl
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";};
using P=pair<ll,ll>;
const ll M = 998244353;
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}
ll mod_pow(ll x, ll a, ll m) { ll an = 1; while(a > 0) { if (a&1) an = an * x % m; x = x * x % m; a >>= 1;} return an;}
void add(ll& x, ll y) {x+=y; x%=M;}; void mul(ll& x, ll y) {x*=y; x%=M;}; template<typename T, typename U> void chmax(T& x, U y) {if (x<y) x=y;}; template<typename T, typename U> void chmin(T& x, U y) {if (x>y) x=y;}
bool vaild(int x, int y, int hh, int ww){return 0<=x&&x<hh&&0<=y&&y<ww;}
int keta(ll a) {int res=0; while(a>0) res+=a%10, a/=10; return res;}
const int up[]={1,-1,0,0}, lf[]={0,0,1,-1};
ll gcd(ll a, ll b) {if (b==0) return a; else return gcd(b, a%b);}

int main() {
  ll n,x,m; cin>>n>>x>>m;
  ll y = x;
  ll t[m];
  ll u[m]; fill(u,u+m,-1);
  ll sm = 0;
  for(ll i=0;i<n;i++) {
    if (u[y] != -1) {
      ll df = sm - u[y];
      ll lf = n - i;
      ll pt = i - t[y];
      sm += lf / pt * df;
      //cout << i << " " << n << " " << (lf%pt) << " " << n - (lf % pt) << endl;
      i = n - (lf % pt);
      //cout << sm << " " << df << " " << lf << " " << i << " " << pt<<endl;
      for(;i<n;i++) {
        sm += y; y = y*y%m;
      }
    } else {
      u[y] = sm; t[y] = i; sm += y;
      y = y*y%m;
    }
  }
  /*
  ll sm2 = 0; y = x;
  for(int i=0;i<n;i++) {
    cout << y << " ";
    sm2 += y; y = y*y%m;
  } cout<<endl;*/
  //cout<<endl;
  cout<<sm<<endl;
  //cout<<sm2<<endl;
}
// ・配列の大きさok？　・priority_queueはgreater？　・debug消した？
// ・落ち着いて。提出まで4分待ってね……WJ……1/10……2/10……

// Thank you for making problems and running the contest
