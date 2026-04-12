//#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 998244353
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
//const ll INF = 1LL << 60;
//typedef pair<ll,ll> P;
typedef pair<int, int> P;
bool chmx(int &a, int b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

bool chmn(int &a, int b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;//thisポインター　thisで自分自身のアドレス
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

int main(){
	int n,s;
	cin >> n>>s;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<mint> q(s+1);
	/*
	rep(i,2*s+1){
		q[i]=0;
	}
	*/
	mint ans=0;
	rep(i,n){
		q[0]+=1;
		vector<mint> q2(s+1);
		rep(j,s+1){
			q2[j]+=q[j];
			if(j+a[i]<=s)q2[j+a[i]]+=q[j];
		}
		q=q2;
		ans+=q[s];
	}
	
	cout<<ans.x<<endl;
    return 0;
}

