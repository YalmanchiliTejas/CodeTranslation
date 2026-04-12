//author:luckYrat(twitter:@luckYrat_)
//<ここに一言>

//せんげん！
#include <iostream>

#include <cmath>
#include <algorithm>
#include <iomanip>

#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>

#include <cctype>
#include <utility>
#include <climits>


//なまえくーかん！
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

//てーすう！
const int mod = 998244353;
const int inf = (1<<30)-1;
const ll linf = (1LL<<62LL)-1;
const double EPS = (1e-10);

//でふぁいん！
#define anyfill(n,s) setw(n) << setfill(s)
#define loop(s) for(int i = 0; s > i; i++)
#define rep(i,q) for(int i = 0; (q) > i; i++)
#define repp(i,n,q) for(int i = n; (q) > i; i++)
#define dep(i,q) for(int i = (q); 0 < i; i--)

//みじかく！
#define pb push_back
#define fir first
#define scn second
#define ednl endl

//いぇすのー！
#define YesNo(a) (a?"Yes":"No")
#define YESNO(a) (a?"YES":"NO")
#define yesno(a) (a?"yes":"no")

//きんぼーnほーこー！！
P ar4[4] = {{0,1},{0,-1},{1,0},{-1,0}};
P ar8[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
/*
確認ポイント
cout << fixed << setprecision(n) << 小数計算//n桁の小数表記になる

計算量は変わらないが楽できるシリーズ
min(max)_element(iter,iter)で一番小さい(大きい)値のポインタが帰ってくる
count(iter,iter,int)でintがiterからiterの間にいくつあったかを取得できる
*/
//B
template <int mod>
struct ModInt{
  int n;
  ModInt():n(0){}
  ModInt(int n_):n(n_ >= 0 ? n_%mod : mod - ((-n_)%mod) ){}

  ModInt &operator+=(const ModInt &p){
    if((n+=p.n) >= mod)n-=mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p){
    n+=mod-p.n;
    if(n >= mod)n-=mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p){
    n = (int) ((1LL*n*p.n)%mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p){
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const {return ModInt(-n);}
  ModInt operator+(const ModInt &p) const {return ModInt(*this) += p;}
  ModInt operator-(const ModInt &p) const {return ModInt(*this) -= p;}
  ModInt operator*(const ModInt &p) const {return ModInt(*this) *= p;}
  ModInt operator/(const ModInt &p) const {return ModInt(*this) /= p;}

  bool operator==(const ModInt &p) const {return n==p.n;}
	bool operator<(const ModInt &p) const {return n<p.n;}
	bool operator>(const ModInt &p) const {return n>p.n;}
	bool operator>=(const ModInt &p) const {return n>=p.n;}
	bool operator<=(const ModInt &p) const {return n<=p.n;}
  bool operator!=(const ModInt &p) const {return n!=p.n;}

  ModInt inverse() const {
    int a = n,b = mod,u = 1,v = 0;
    while(b){
      int t = a/b;
      a -= t*b; swap(a,b);
      u -= t*v; swap(u,v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t z) const {
    ModInt ret(1),mul(n);
    while(z > 0){
      if(z & 1) ret *= mul;
      mul *= mul;
      z >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p){
    return os << p.n;
  }
  friend istream &operator>>(istream &is, ModInt &a){
    int64_t t;
    is >> t;
    a = ModInt<mod> (t);
    return (is);

  }
};
using mint = ModInt<mod>;
//E
int n,s;
vector<int> A;
mint dp[3002][9000];//nw,p
__attribute__((constructor))
void initial() {
 cin.tie(0);
 ios::sync_with_stdio(false);
}
int main(){
	cin>>n>>s;
	
	for(int i = 0; n > i; i++){
		int t;cin>>t;
		A.push_back(t);
	}
	for(int i = 0; n >= i; i++){
		dp[i][0]=i+1;
	}
	for(int i = 0; n >= i; i++){
		for(int j = 0; s >= j; j++){
			if(j)dp[i+1][j]+=dp[i][j];
			dp[i+1][j+A[i]]+=dp[i][j];
		}
	}
	mint ans = 0;
	for(int i = 0; n >= i; i++){
		ans += dp[i][s];
	}
	cout << ans << endl;
}