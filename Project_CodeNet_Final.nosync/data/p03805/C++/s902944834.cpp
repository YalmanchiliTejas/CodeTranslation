#include "bits/stdc++.h"
using namespace std;
using     ll=long long;
using    vll=vector<   ll>;
using   vvll=vector<  vll>;
using  vvvll=vector< vvll>;
using vvvvll=vector<vvvll>;
constexpr ll INF = 1LL << 60;
struct Fast{ //cin,cout高速化のおまじない＋桁数指定
	Fast(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(std::numeric_limits<double>::max_digits10); }
} fast;
#define rep(i, S, E)  for (ll i = (S); i <= (E); i++)
#define dep(i, E, S)  for (ll i = (E); i >= (S); i--)
#define each(e, v) for (auto&& e : v)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmax(m,v[i]); return m; }
template<class T> inline T MinE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmin(m,v[i]); return m; }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v,0,(ll)v.size()-1); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v,0,(ll)v.size()-1); }
template<class T> inline T Sum(vector<T> &v,ll S,ll E){ T s=T(); rep(i,S,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v) { return Sum(v,0,v.size()-1); }
template<class T> inline ll sz(T &v){ return (ll)v.size(); }
template<class T> inline T POW(T a, ll n){ T r=1; for (; n>0; n>>=1, a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a, ll n){ return POW((ll)a, n); }
inline ll CEIL(ll a, ll b){ return (a+b-1)/b; }

//pair用テンプレート
using   pll=pair<ll,ll>;
using  vpll=vector< pll>;
using vvpll=vector<vpll>;
template<class T,class S> inline pair<T,S>& operator+=(pair<T,S> &a,const pair<T,S> &b){ a.first+=b.first; a.second+=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator-=(pair<T,S> &a,const pair<T,S> &b){ a.first-=b.first; a.second-=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator*=(pair<T,S> &a,const pair<T,S> &b){ a.first*=b.first; a.second*=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator/=(pair<T,S> &a,const pair<T,S> &b){ a.first/=b.first; a.second/=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator%=(pair<T,S> &a,const pair<T,S> &b){ a.first%=b.first; a.second%=b.second; return a; }
template<class T,class S,class R> inline pair<T,S>& operator+=(pair<T,S> &a,R b){ a.first+=b; a.second+=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator-=(pair<T,S> &a,R b){ a.first-=b; a.second-=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator*=(pair<T,S> &a,R b){ a.first*=b; a.second*=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator/=(pair<T,S> &a,R b){ a.first/=b; a.second/=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator%=(pair<T,S> &a,R b){ a.first%=b; a.second%=b; return a; }
template<class T,class S,class R> inline pair<T,S> operator+(const pair<T,S> &a,R b){ pair<T,S> c=a; return c+=b; }
template<class T,class S,class R> inline pair<T,S> operator-(const pair<T,S> &a,R b){ pair<T,S> c=a; return c-=b; }
template<class T,class S,class R> inline pair<T,S> operator*(const pair<T,S> &a,R b){ pair<T,S> c=a; return c*=b; }
template<class T,class S,class R> inline pair<T,S> operator/(const pair<T,S> &a,R b){ pair<T,S> c=a; return c/=b; }
template<class T,class S,class R> inline pair<T,S> operator%(const pair<T,S> &a,R b){ pair<T,S> c=a; return c%=b; }
template<class T,class S,class R> inline pair<T,S> operator-(R b,const pair<T,S> &a){ pair<T,S> c=-a; return c+=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a){ pair<T,S> c=a; return c*=(-1); }
template<class T,class S> inline ostream &operator<<(ostream &os,const pair<T,S> &a){ return os << a.first << ' ' << a.second; }


void solve()
{
	ll n,m;  cin >> n >> m;
	//vector<pair<ll,ll>> ab(n);
	set<pll> st;

	rep(i,0,m-1){
		ll a; ll b; cin>>a>>b;a--;b--;
		st.insert({a,b});
		st.insert({b,a});
	}

	deque<ll> idxAry;
	rep(i,1,n-1){
		idxAry.push_back(i);
	}

	ll ans=0;
	do{
		deque<ll> tmp=idxAry;
		tmp.push_front(0);

		{
			bool isall=true;
			rep(i,1,sz(tmp)-1) if (!(st.count({tmp[i-1],tmp[i]})==1)) isall=false;
			if (isall){
				ans++;
			}
		}

	} while (next_permutation(idxAry.begin(), idxAry.end()));
	
	cout << ans << '\n';
}


int main(){
#if 1
	solve();
#else
	ll t;  cin >> t;
	rep(i, 0, t-1){
		solve();
	}
#endif
	return 0;
}
