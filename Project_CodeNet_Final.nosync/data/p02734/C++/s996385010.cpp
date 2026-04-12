#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mset(x,y) memset(x,y,sizeof(x))
#define rep(i,n) for(int i=0;i<int(n);i++)
#define per(i,n) for(int i=int(n)-1;i>=0;i--)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
using namespace std;
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef LOCAL
#define dmp(...) _dmp(#__VA_ARGS__, __VA_ARGS__)
#else
#define dmp(...) (__VA_ARGS__)
#endif
template<class T> using vt=vector<T>;
template<class T> using vvt=vt<vt<T>>;
template<class TA,class TB> void chmax(TA&a,TB b){if(a<b)a=b;}
template<class TA,class TB> void chmin(TA&a,TB b){if(b<a)a=b;}
template<class TA,class TB>
ostream& operator<<(ostream& os,const pair<TA,TB>& p){
	return os<<"{"<<p.fi<<","<<p.se<<"}";
}
template<class T> ostream& operator<<(ostream& os,const vt<T>& v){
	os<<"{";for(auto& e:v)os<<e<<",";return os<<"}";
}
template<class TH> void _dmp(const char *sdbg, TH h){cout<<sdbg<<"="<<h<<endl;}
template<class TH, class... TA> void _dmp(const char *sdbg, TH h, TA...a){
while(*sdbg!=',')cout<<*sdbg++;cout<<"="<<h<<","; _dmp(sdbg+1, a...);
}
template<class T> void make_unique(vt<T>& v) {
	sort(all(v));v.erase(unique(all(v)),v.end());
}
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
int ri(){int x;cin>>x;return x;}
ll rll(){ll x;cin>>x;return x;}
vi rvi(int n){vi v;rep(i,n)v.pb(ri());return v;}
template<int mod>
struct modint{
	int v;
	modint(ll vv=0){s(vv%mod+mod);}
	modint& s(int vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modint operator-()const{return modint()-*this;}
	modint& operator+=(const modint&rhs){return s(v+rhs.v);}
	modint&operator-=(const modint&rhs){return s(v+mod-rhs.v);}
	modint&operator*=(const modint&rhs){
		v=ll(v)*rhs.v%mod;
		return *this;
	}
	modint&operator/=(const modint&rhs){return *this*=rhs.inv();}
	modint operator+(const modint&rhs)const{return modint(*this)+=rhs;}
	modint operator-(const modint&rhs)const{return modint(*this)-=rhs;}
	modint operator*(const modint&rhs)const{return modint(*this)*=rhs;}
	modint operator/(const modint&rhs)const{return modint(*this)/=rhs;}
	modint pow(int n)const{
		modint res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modint inv()const{return pow(mod-2);}
	/*modint inv()const{
		int x,y;
		int g=egcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modint(x);
	}*/
	friend modint operator+(int x,const modint&y){return modint(x)+y;}
	friend modint operator-(int x,const modint&y){return modint(x)-y;}
	friend modint operator*(int x,const modint&y){return modint(x)*y;}
	friend modint operator/(int x,const modint&y){return modint(x)/y;}
	friend ostream& operator<<(ostream&os,const modint&m){return os<<m.v;}
	friend istream& operator>>(istream&is,modint&m){
		ll x;is>>x;
		m=modint(x);
		return is;
	}
	bool operator<(const modint&r)const{return v<r.v;}
	bool operator==(const modint&r)const{return v==r.v;}
	bool operator!=(const modint&r)const{return v!=r.v;}
	explicit operator bool()const{return v;}
};
using mint=modint<998244353>;
int n,m;
int a[3010];
mint D[3010][3010],ans[3010];
void f() {
	rep(i,n) {
		if(!i) {
			rep(j,m+1)D[i][j]=0;
		} else {
			rep(j,m+1) {
				D[i][j]=D[i-1][j];
				if(j>=a[i]) {
					D[i][j]+=D[i-1][j-a[i]];
				}
			}
		}
		D[i][a[i]]+=i+1;
		rep(j,m+1){
			ans[j]+=D[i][j];
		}
	}
}
void MAIN() {
	cin>>n>>m;
	rep(i,n)cin>>a[i];
	f();
	cout<<ans[m];
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int T=1;
	//cin>>T;
	for(int tt=1;tt<=T;tt++) {
		MAIN();
	}
	return 0;
}