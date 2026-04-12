//sub-BOF

// laptop
// author: Tqk

//#define _AOJ_
#define _C_INPUT_

#pragma region template

#pragma region basic
//#pragma GCC optimize ("O3")
#pragma warning(disable: 4455 4244 4067 4068)
#pragma GCC target ("avx")
#pragma GCC diagnostic ignored "-Wliteral-suffix"
#define NOMINMAX
#include "bits/stdc++.h"
using namespace std;
typedef int64_t lint;
typedef long double ld;
typedef string cs;
#define linf 1152921504606846976
#pragma endregion

#pragma region rep
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
#pragma endregion

#pragma region io
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
#ifdef __ENV_TQK__
inline bool deb(){ SetConsoleTextAttribute(hConsole,10); return(cout<<'\n',0); }
template <class T>
inline bool deb(T t){ return(SetConsoleTextAttribute(hConsole,12),cout<<t<<'\n',SetConsoleTextAttribute(hConsole,10),0); }
template <class Head,class... Tail>
inline bool deb(Head head,Tail... tail){
	SetConsoleTextAttribute(hConsole,12);
	cout<<head<<' ';deb(move(tail)...);return 0;
}
#define dsp(ex) sp(ex)
#define dno(ex) no(ex)
#define look(v) SetConsoleTextAttribute(hConsole,12),cout<<#v<<": ",deb(v);
#else
#define deb(...) 0
#define dsp(ex) 0
#define dno(ex) 0
#define look(v) 0
#endif

#pragma endregion

#pragma region TA
#define lin(...) lint __VA_ARGS__;in(__VA_ARGS__)
#define stin(...) string __VA_ARGS__;in(__VA_ARGS__)
#define vin(type,name,size) vector<type> name(size);in(name)
#define tvin(ty1,ty2,name,size,val) vector<ty1>_in_vec(size);vector<ty2>a(size);in(_in_vec);{ty1 e;rep(size)e=_in_vec[i],name[i]=val;}
#define all(v) v.begin(),v.end()
#define pb push_back
#define fi e.first
#define se e.second
#define YES(c) cout<<((c)?"YES\n":"NO\n"),0
#define Yes(c) cout<<((c)?"Yes\n":"No\n"),0
#define POSSIBLE(c) cout<<((c)?"POSSIBLE\n":"IMPOSSIBLE\n"),0
#define Possible(c) cout<<((c)?"Possible\n":"Impossible\n"),0
#define o(p) cout<<p<<endl,0
#define sp(p) cout<<p<<" ",0
#define no(p) cout<<p,0
#define psort(l,r) if(l>r)swap(l,r);
inline constexpr lint gcd(lint a,lint b){ if(!a||!b)return 0;while(b){ lint c=b;b=a%b;a=c; }return a; }
template<typename T>
inline constexpr bool chmin(T &mn,const T &cnt){ if(mn>cnt){ mn=cnt;return 1; } else return 0; }
template<typename T>
inline constexpr bool chmax(T &mx,const T &cnt){ if(mx<cnt){ mx=cnt;return 1; } else return 0; }
#define ve(type) vector<type>
#define fn(ty1,ty2,ex) [](ty1 l,ty2 r){ return(ex); }
#define lfn(ex) [](lint l,lint r){ return(ex); }
template<typename T,class F>
T fold(vector<T>a,F f,T e=0,lint l=0,lint r=linf){ for(lint i=l;i<r&&i<a.size();++i)e=f(e,a[i]);return e; }

#pragma endregion

#pragma region mint
#define md_tmp template<uint_fast64_t md=1000000007>
md_tmp class modint{
	using u64=uint_fast64_t;

public:
	u64 a;

	constexpr modint(const lint x=0) noexcept: a((x+md)%md){}
	constexpr u64 &value() noexcept{ return a; }
	constexpr const u64 &value() const noexcept{ return a; }
	constexpr modint operator+(const modint rhs) const noexcept{
		return modint(*this)+=rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept{
		return modint(*this)-=rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept{
		return modint(*this)*=rhs;
	}
	constexpr modint operator^(const lint rhs) const noexcept{
		return modint(*this)^=rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept{
		return modint(*this)/=rhs;
	}
	constexpr modint &operator+=(const modint rhs) noexcept{
		a+=rhs.a;
		if(a>=md)a-=md;
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept{
		if(a<rhs.a)a+=md;
		a-=rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept{
		a=a*rhs.a%md;
		return *this;
	}
	constexpr modint &operator^=(const lint rhs) noexcept{
		if(!rhs)return *this=1;
		u64 exp=rhs-1;
		modint base=this->a;
		while(exp){
			if(exp&1)*this*=base;
			base*=base;
			exp>>=1;
		}
		return *this;
	}
	constexpr modint &operator/=(const modint rhs) noexcept{
		a=(*this*(rhs^(md-2))).a;
		return *this;
	}
};
using mint=modint<>;
md_tmp istream& operator>>(istream& os,modint<md>& m){
	os>>m.a,m.a%=md;
	return os;
}
md_tmp ostream& operator<<(ostream& os,const modint<md>& m){
	return os<<m.a;
}
md_tmp modint<md> ncr(lint n,lint r){//O(r)//use bigncr
	if(n<r||n<0||r<0)return modint<md>(0);
	modint<md>ncr_res=1,ncr_div=1;
	rep(r)ncr_res*=(n-i),ncr_div*=(r-i);
	return ncr_res/ncr_div;
}
//lint ncri(lint n,lint r){//O(r)
//	if(n<r||n<0||r<0)return 0;
//	lint ncr_res=1,ncr_div=1;
//	rep(r)ncr_res*=(n-i),ncr_div*=(r-i);
//	return ncr_res/ncr_div;
//}
#ifndef _AOJ_
inline modint<> operator""m(const unsigned long long n){ return modint<>(n); }
inline lint operator""z(const unsigned long long n){ return lint(n); }
#endif
#pragma endregion

#pragma region P
class P{ public:lint f,s; P(lint a,lint b):f(a),s(b){}; P():f(0),s(0){}; };
istream& operator>>(istream& os,P& p){ os>>p.f>>p.s;return os; }
constexpr bool operator<(const P& l,const P& r){ return(l.f-r.f?l.f<r.f:l.s<r.s); }
constexpr bool operator>(const P& l,const P& r){ return(l.f-r.f?l.f>r.f:l.s>r.s); }
constexpr bool operator<=(const P& l,const P& r){ return!(l.f-r.f?l.f>r.f:l.s>r.s); }
constexpr bool operator>=(const P& l,const P& r){ return!(l.f-r.f?l.f<r.f:l.s<r.s); }
#pragma endregion

#pragma region rec_lambda
/*
usage: 
	auto res=rec([&](auto f,int n...){
		if(n<2)return n;
		return f(n-=2);
	})(114514);
*/
template<typename F>
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
[[nodiscard]]
#elif defined(__GNUC__) && (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
__attribute__((warn_unused_result))
#endif  // defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
static inline constexpr decltype(auto)
rec(F&& f) noexcept{
	return[f = std::forward<F>(f)](auto&&... args) {
		return f(f,std::forward<decltype(args)>(args)...);
	};
}
#pragma endregion

#pragma region start
struct Start{
	Start(){
#ifndef _C_INPUT_
		cin.tie(0),cout.tie(0);
		ios::sync_with_stdio(0);
#endif
		cout<<fixed<<setprecision(10);
	}
} __start;
#pragma endregion

#pragma endregion

#pragma region const
#define MAXN 101010
#define mod 1000000007//998244353
const ld pi=3.14159265358979323846;
const ld tau=(1.+sqrt(5))/2.;
P d4[4]={P(1,0),P(0,1),P(-1,0),P(0,-1)};
P d8[8]={P(1,0),P(1,1),P(0,1),P(-1,1),P(-1,0),P(-1,-1),P(0,-1),P(1,-1)};
#pragma endregion

//solve{

void solve(lint a, lint b, lint c, lint x, lint y){
	if(x>y)swap(x,y),swap(a,b);
	lint ans=linf;
	rep(100001){
		lint tmp=2*i*c,xx=x-i,yy=y-i;
		tmp+=max(0z,xx*a)+max(0z,yy*b);
		chmin(ans,tmp);
	}
	out(ans);
}

//}//solve

int main(){
    lint A;
    scanf("%lld",&A);
    lint B;
    scanf("%lld",&B);
    lint C;
    scanf("%lld",&C);
    lint X;
    scanf("%lld",&X);
    lint Y;
    scanf("%lld",&Y);
    solve(A, B, C, X, Y);
}

//sub-EOF