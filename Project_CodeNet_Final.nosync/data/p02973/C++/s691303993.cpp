

        /*vvv>
        zzzzzI
 .---.  zzuzuI                 .vgggg&,.
+++++=  dAC:|I  .WbbWo       JMM9^```?TMB`  ..&gNNg,.   gggggggJ,   qgggggggg] (&&&&&&&&[   c+OA&J,   (&&&&&&+J,   .cJeAA&-.  (&&&&&&&&x   .&AA&=-.
+++++=  dTqk|I  Xpbpbp      JM#`           (M#^   ?MMp  MM|   +TMN. JMF      ' |yk      ` dVY    7Vk,  Vy     XV  cVf     ?Y!  JM         V$      `
+++++=  dcf:|I  Xppppp      dMN           .MM+     .MM  MM|     MM] JMMMMMM+   |@tqkoh)  ,y0      (V$  yyyyyyyV7  VV           JMWyZWr    TWVVVVW&,
++++++  d7qk|0  Xppppp      ^HMN,    _.db  WMm,   .MMF  MM|   ..MM` JMF      . |yk       .WV&.   .XW'  yy   4yn.  jyn      +.  JM                #S
`++++`  ?ZZZX=  ?WWWW=        -THMMMMH9^    (TMMMMM9!   MMMMMMM""   JMMMMMMMME |UU.        ?TUUUUY=    UU.   (UU-  ^7TUUUV7!   JUUUUUUUU  7TUNKO*/

//Ricty Diminished
#include "bits/stdc++.h"
using namespace std;typedef long long lint;typedef vector<lint> liv;
//#define rep(i,n) for(int i=0;i<n;++i)
#define all(v) v.begin(),v.end()
#define linf 1152921504606846976
#define MAXN 200100
#define md_1e9_7 1000000007
#define md_998244353 998244353

#define pb push_back
#define _vcppunko4(tuple) _getname4 tuple
#define _getname4(_1,_2,_3,_4,name,...) name
#define _getname3(_1,_2,_3,name,...) name
#define _trep2(tuple) _rep2 tuple
#define _trep3(tuple) _rep3 tuple
#define _trep4(tuple) _rep4 tuple
#define _rep1(n) for(lint i=0;i<n;++i)
#define _rep2(i,n) for(lint i=0;i<n;++i)
#define _rep3(i,a,b) for(lint i=a;i<b;++i)
#define _rep4(i,a,b,c) for(lint i=a;i<b;i+=c)
#define _trrep2(tuple) _rrep2 tuple
#define _trrep3(tuple) _rrep3 tuple
#define _trrep4(tuple) _rrep4 tuple
#define _rrep1(n) for(lint i=n-1;i>=0;--i)
#define _rrep2(i,n) for(lint i=n-1;i>=0;--i)
#define _rrep3(i,a,b) for(lint i=b-1;i>=a;--i)
#define _rrep4(i,a,b,c) for(lint i=a+(b-a-1)/c*c;i>=a;i-=c)
template<class T>
istream& operator>>(istream& is,vector<T>& vec);
template<class T,size_t size>
istream& operator>>(istream& is,array<T,size>& vec);
template<class T,class L>
istream& operator>>(istream& is,pair<T,L>& p);
template<class T>
ostream& operator<<(ostream& os,vector<T>& vec);
template<class T,class L>
ostream& operator<<(ostream& os,pair<T,L>& p);
template<class T>
istream& operator>>(istream& is,vector<T>& vec){ for(T& x: vec) is>>x;return is; }
template<class T,class L>
istream& operator>>(istream& is,pair<T,L>& p){ is>>p.first;is>>p.second;return is; }
//template<class T>
//ostream& operator<<(ostream& os,vector<T>& vec){ os<<vec[0];rep(i,1,vec.size())os<<' '<<vec[i];return os; }
//template<class T>
//ostream& operator<<(ostream& os,deque<T>& deq){ os<<deq[0];rep(i,1,deq.size())os<<' '<<deq[i];return os; }
template<class T,class L>
ostream& operator<<(ostream& os,pair<T,L>& p){ os<<p.first<<" "<<p.second;return os; }

inline void in(){}
template <class Head,class... Tail>
inline void in(Head&& head,Tail&&... tail){ cin>>head;in(move(tail)...); }
template <class T>
inline bool out(T t){ cout<<t<<'\n';return 0; }
inline bool out(){ cout<<'\n';return 0; }
template <class Head,class... Tail>
inline bool out(Head head,Tail... tail){ cout<<head<<' ';out(move(tail)...);return 0; }

template<typename T>
vector<T> make_v(size_t a){ return vector<T>(a); }

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){ t=v; }

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}//http://beet-aizu.hatenablog.com/entry/2018/04/08/145516

#define rep(...) _vcppunko4((__VA_ARGS__,_trep4,_trep3,_trep2,_rep1))((__VA_ARGS__))
#define rrep(...) _vcppunko4((__VA_ARGS__,_trrep4,_trrep3,_trrep2,_rrep1))((__VA_ARGS__))
#define each(v) for(auto &i:v)
#define lin(...) lint __VA_ARGS__;in(__VA_ARGS__)
#define stin(...) string __VA_ARGS__;in(__VA_ARGS__)
#define vin(type,name,size) vector<type> name(size);in(name)
#define fi e.first
#define se e.second
#define YES(c) cout<<((c)?"YES\n":"NO\n"),0
#define Yes(c) cout<<((c)?"Yes\n":"No\n"),0
#define o(p) cout<<p<<endl,0
#define sp(p) cout<<p<<" "
#define deb(p) cerr<<p<<endl,0
#define dd(n) cout<<fixed<<setprecision(n)

#define inf linf

//mint
#define md_tmp template<uint_fast64_t md=1000000007>
md_tmp class mint{
	using u64=uint_fast64_t;

public:
	u64 a;

	constexpr mint(const u64 x=0) noexcept: a(x%md){}
	constexpr u64 &value() noexcept{ return a; }
	constexpr const u64 &value() const noexcept{ return a; }
	constexpr mint operator+(const mint rhs) const noexcept{
		return mint(*this)+=rhs;
	}
	constexpr mint operator-(const mint rhs) const noexcept{
		return mint(*this)-=rhs;
	}
	constexpr mint operator*(const mint rhs) const noexcept{
		return mint(*this)*=rhs;
	}
	constexpr mint operator^(const lint rhs) const noexcept{
		return mint(*this)^=rhs;
	}
	constexpr mint operator/(const mint rhs) const noexcept{
		return mint(*this)/=rhs;
	}
	constexpr mint &operator+=(const mint rhs) noexcept{
		a+=rhs.a;
		if(a>=md)a-=md;
		return *this;
	}
	constexpr mint &operator-=(const mint rhs) noexcept{
		if(a<rhs.a)a+=md;
		a-=rhs.a;
		return *this;
	}
	constexpr mint &operator*=(const mint rhs) noexcept{
		a=a*rhs.a%md;
		return *this;
	}
	constexpr mint &operator^=(const lint rhs) noexcept{
		if(!rhs)return *this=1;
		u64 exp=rhs-1;
		mint base=this->a;
		while(exp){
			if(exp&1)*this*=base;
			base*=base;
			exp>>=1;
		}
		return *this;
	}
	constexpr mint &operator/=(const mint rhs) noexcept{
		a=(*this*(rhs^(md-2))).a;
		return *this;
	}
};
md_tmp istream& operator>>(istream& os,mint<md>& m){
	os>>m.a,m.a%=md;
	return os;
}
md_tmp ostream& operator<<(ostream& os,const mint<md>& m){
	return os<<m.a;
}
md_tmp mint<md> ncr(lint n,lint r){
	if(n<r||n<0||r<0)return mint<md>(0);
	mint<md>ncr_res=1,ncr_div=1;
	rep(r)ncr_res*=(n-i),ncr_div*=(r-i);
	return ncr_res/ncr_div;
}
mint<> operator""m(unsigned long long n){ return mint<>(n); }
mint<998244353> operator""m9(unsigned long long n){ return mint<998244353>(n); }
mint<1000003> operator""m3(unsigned long long n){ return mint<1000003>(n); }
using mi=mint<>;

//P
class P{ public:lint x,y; };
istream& operator>>(istream& os,P& p){ os>>p.x>>p.y;return os; }
bool operator<(P& l,P& r){ return(l.x-r.x?l.x<r.x:l.y<r.y); }
bool operator>(P& l,P& r){ return(l.x-r.x?l.x>r.x:l.y>r.y); }
class co: public P{
public:
	constexpr co() noexcept:P({0,0}){}
	constexpr co(lint x,lint y) noexcept: P({x,y}){}
	constexpr const lint &value() const noexcept{ return x*x+y*y; }
	constexpr co operator-() const noexcept{
		return *this*-1;
	}
	constexpr bool operator==(const co rhs) const noexcept{
		return x==rhs.x&&y==rhs.y;
	}
	constexpr bool operator!=(const co rhs) const noexcept{
		return x!=rhs.x&&y!=rhs.y;
	}
	constexpr co operator+(const co rhs) const noexcept{
		return co(*this)+=rhs;
	}
	constexpr co operator-(const co rhs) const noexcept{
		return co(*this)-=rhs;
	}
	constexpr co operator*(const lint rhs) const noexcept{
		return co(*this)*=rhs;
	}
	constexpr double operator/(const co rhs) const noexcept{
		if(!x&&!y)return 0;
		if(!rhs.x&&!rhs.y)return 101010.10101;
		if(!(x*rhs.y)^!(y*rhs.x))return 101010.10101;
		return(x*rhs.y-y*rhs.x?101010.10101:(!rhs.x?y/rhs.y:x/rhs.x));
	}
	constexpr co &operator+=(const co rhs) noexcept{
		x+=rhs.x;
		y+=rhs.y;
		return *this;
	}
	constexpr co &operator-=(const co rhs) noexcept{
		x-=rhs.x;
		y-=rhs.y;
		return *this;
	}
	constexpr co &operator*=(const lint rhs) noexcept{
		x*=rhs;
		y*=rhs;
		return *this;
	}
};



int main(){
	lin(n);
	vin(lint,a,n);
	multiset<lint,greater<lint>>q;
	q.insert(a[0]);
	rep(i,1,n){
		auto it=q.upper_bound(a[i]);
		if(it!=q.end()){
			q.erase(it);
		}
		q.insert(a[i]);
	}
	o(q.size());
}

//sub-EOF
