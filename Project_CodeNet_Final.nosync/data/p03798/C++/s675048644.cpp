//sub-BOF
#define _AOJ_
        /*vvv>
        zzzzzI
 .---.  zzuzuI                 .vgggg&,.
+++++=  dAC:|I  .WbbWo       JMM9^```?TMB`  ..&gNNg,.   gggggggJ,   qgggggggg] (&&&&&&&&[   c+OA&J,   (&&&&&&+J,   .cJeAA&-.  (&&&&&&&&x   .&AA&=-.
+++++=  dTqk|I  Xpbpbp      JM#`           (M#^   ?MMp  MM|   +TMN. JMF      ' |yk      ` dVY    7Vk,  Vy     XV  cVf     ?Y!  JM         V$      `
+++++=  dcf:|I  Xppppp      dMN           .MM+     .MM  MM|     MM] JMMMMMM+   |@tqkoh)  ,y0      (V$  yyyyyyyV7  VV           JMWyZWr    TWVVVVW&,
++++++  d7qk|0  Xppppp      ^HMN,    _.db  WMm,   .MMF  MM|   ..MM` JMF      . |yk       .WV&.   .XW'  yy   4yn.  jyn      +.  JM                #S
`++++`  ?ZZZX=  ?WWWW=        -THMMMMH9^    (TMMMMM9!   MMMMMMM""   JMMMMMMMME |UU.        ?TUUUUY=    UU.   (UU-  ^7TUUUV7!   JUUUUUUUU  7TUNKO*/


//basic
#pragma GCC target("sse4")
#include "bits/stdc++.h"
using namespace std;
typedef long long lint;
typedef long double ld;
typedef string cs;
#define all(v) v.begin(),v.end()
#define pb push_back

//rep
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
#define rep(...) _vcppunko4((__VA_ARGS__,_trep4,_trep3,_trep2,_rep1))((__VA_ARGS__))
#define per(...) _vcppunko4((__VA_ARGS__,_trrep4,_trrep3,_trrep2,_rrep1))((__VA_ARGS__))
#define each(c) for(auto &e:c)

//io
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
template<class T,class L>
ostream& operator<<(ostream& os,pair<T,L>& p){ os<<p.first<<" "<<p.second;return os; }
template<class T>
ostream& operator<<(ostream& os,vector<T>& vec){ os<<vec[0];rep(i,1,vec.size())os<<' '<<vec[i];return os; }
template<class T>
ostream& operator<<(ostream& os,deque<T>& deq){ os<<deq[0];rep(i,1,deq.size())os<<' '<<deq[i];return os; }

#ifdef __ENV_TQK__
#include<Windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
inline void in(){ SetConsoleTextAttribute(hConsole,10); }
template <class Head,class... Tail>
inline void in(Head&& head,Tail&&... tail){
	SetConsoleTextAttribute(hConsole,15);
	cin>>head;in(move(tail)...);
}
#else
inline void in(){}
template <class Head,class... Tail>
inline void in(Head&& head,Tail&&... tail){ cin>>head;in(move(tail)...); }
#endif



inline bool out(){ return(cout<<'\n',0); }
template <class T>
inline bool out(T t){ return(cout<<t<<'\n',0); }
template <class Head,class... Tail>
inline bool out(Head head,Tail... tail){ cout<<head<<' ';out(move(tail)...);return 0; }
template <class T>
inline void alloc(T &c,lint s){ rep(c.size())c[i].resize(s); }
#define alc alloc

//TA
#define lin(...) lint __VA_ARGS__;in(__VA_ARGS__)
#define stin(...) string __VA_ARGS__;in(__VA_ARGS__)
#define vin(type,name,size) vector<type> name(size);in(name)
#define vvin(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
#define fi e.first
#define se e.second
#define YES(c) cout<<((c)?"YES\n":"NO\n"),0
#define Yes(c) cout<<((c)?"Yes\n":"No\n"),0
#define POSSIBLE(c) cout<<((c)?"POSSIBLE\n":"IMPOSSIBLE\n"),0
#define Possible(c) cout<<((c)?"Possible\n":"Impossible\n"),0
#define o(p) cout<<p<<endl,0
#define sp(p) cout<<p<<" "
#define no(p) cout<<p
inline constexpr lint gcd(lint a,lint b){ if(!a||!b)return 0;while(b){ lint c=b;b=a%b;a=c; }return a; }
template<typename T>
inline constexpr bool chmin(T &mn,const T &cnt){ if(mn>cnt){ mn=cnt;return 1; } else return 0; }
template<typename T>
inline constexpr bool chmax(T &mx,const T &cnt){ if(mx<cnt){ mx=cnt;return 1; } else return 0; }
#define ve(type) vector<type>
#define fn(ty1,ty2,ex) [](ty1 a,ty2 b){ return(ex); }
#define lfn(ex) [](lint a,lint b){ return(ex); }

//other
#ifdef __ENV_TQK__
#define deb(p) cout<<p<<endl,0
#else
#define deb(p) 0
#endif
struct Fastio{
	Fastio(){
		cin.tie(0),cout.tie(0);
		ios::sync_with_stdio(0);
		cout<<fixed<<setprecision(10);
	}
} __fastio;


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
#ifndef _AOJ_
mint<> operator""m(const unsigned long long n){ return mint<>(n); }
mint<998244353> operator""m9(const unsigned long long n){ return mint<998244353>(n); }
mint<1000003> operator""m3(const unsigned long long n){ return mint<1000003>(n); }
#endif


//const
#define linf 1152921504606846976
#define inf linf
#define MAXN 330
#define md_1e9_7 1000000007
#define md_998244353 998244353
#define pi 3.14159265358979323846
//#define mod md_1e9_7
const int d4[5]={0,1,0,-1,0};

//main------

class P{ public:lint f,s; P(lint a,lint b):f(a),s(b){}; P():f(0),s(0){}; };
istream& operator>>(istream& os,P& p){ os>>p.f>>p.s;return os; }
bool operator<(const P& l,const P& r){ return(l.f-r.f?l.f<r.f:l.s<r.s); }
bool operator>(const P& l,const P& r){ return(l.f-r.f?l.f>r.f:l.s>r.s); }

int maain(){
	lin(n,m);
	mint<> ans=(n==m?2:1);
	if(abs(n-m)>1)return out(0);
	rep(i,1,n+1)ans*=i;
	rep(i,1,m+1)ans*=i;
	out(ans);
}

int main(){
	lin(n);
	stin(s);s+=s;
	rep(a,4){
		string ans;ans.resize(2*n);
		ans[0]=(1&(a>>1)?'W':'S');
		ans[1]=((1&a)?'W':'S');
		rep(i,2,2*n){
			ans[i]='S';
			if(((ans[i-1]=='S')^(s[i-1]=='o'))^(ans[i]!=ans[i-2]))ans[i]='W';
		}//out(ans.substr(0,n));
		if(ans.substr(0,n)==ans.substr(n,n))return out(ans.substr(0,n));
	}
	out(-1);
}

//sub-EOF
