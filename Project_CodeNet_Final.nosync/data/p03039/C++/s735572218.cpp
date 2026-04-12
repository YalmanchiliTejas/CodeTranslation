#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <string>
#include <queue>
#include <functional>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//	英語は 26 文字

//	common
namespace{
	#define		CAST( T, val )		( (T)( val ) )
	#define		CASE( lb )			break; case lb:
	#define		CASE_CONT( lb )		case lb:
	#define		CASE_DEF			break; default:
	#define		For( i, s )			for(int i= 0, forEnd##i= CAST( int, s ); i< forEnd##i; ++i)
	#define		ForA( i, a, s )		for(int i= CAST( int, a ), forEnd##i= CAST( int, s ); i< forEnd##i; ++i)
	#define		ForR( i, s )		for(int i= s; i>= 0; i--)
	#define		ForRA( i, s, e )	for(int i= s; i>= e; i--)
	#define		ForItr( itr, con )	for(auto itr= con.begin(), forEnd##itr= con.end(); itr!= forEnd##itr; ++itr)
	#define		ForRItr( itr, con )	for(auto itr= con.rbegin(), forEnd##itr= con.rend(); itr!= forEnd##itr; ++itr)
	#define		ForStr( i, str )	for(int i= 0; str[i]; ++i)
	#define		GOTO( lb )			goto lb
	#define		LABEL( lb )			lb:
	#define		ALL( con )			(con).begin(), (con).end()

	template <typename T, typename K> struct Pair{ T fst; K snd; };
	template<typename T, typename K> std::istream& operator >>(std::istream& in, Pair<T,K>& p){ return in>> p.fst>> p.snd; }
	template <typename T, typename K, typename H> struct Trir{ T fst; K snd; H thd; };
	template<typename T, typename K, typename H> std::istream& operator >>(std::istream& in, Trir<T,K,H>& p){ return in>> p.fst>> p.snd>> p.thd; }

	typedef		long long			xint;
	typedef		unsigned long long	uxint;
	typedef		unsigned int		uint;
	typedef		unsigned char		uchar;
	typedef		unsigned short		ushort;
	typedef		vector<int>			Vi;
	typedef		vector<xint>		Vx;
	typedef		vector<double>		Vd;
	typedef		Pair<int,int>		Pii;
	typedef		vector<Pii>			VPii;
	typedef		Trir<int,int,int>	Tiii;
	typedef		vector<Pii>			VTiii;

	const int Ten5 = 100000;		//	10^5
	const int Ten6 = 1000000;	//	10^6
	const double EPS = 0.00000000023283064365386962890625;	//	2^-32
}
//	min-max-mod
namespace{
	//	合同式
	class Mod{public:
		typedef	xint T;	//	型
		static T N;	//	法

		Mod operator +(T v) const{ return Mod(x+v%N); }
		Mod operator +(Mod m) const{ return Mod(x+m.x); }
		Mod operator +=(T v){ return *this= Mod(x+v%N); }
		Mod operator +=(Mod m){ return *this= Mod(x+m.x); }
		Mod operator -(T v) const{ return Mod(x-v+N); }
		Mod operator -(Mod m) const{ return Mod(x-m.x+N); }
		Mod operator -=(T v){ return *this= Mod(x-v+N); }
		Mod operator -=(Mod m){ return *this= Mod(x-m.x+N); }
		Mod operator *(T v) const{ return Mod(x*v); }
		Mod operator *(Mod m) const{ return Mod(x*m.x); }
		Mod operator *=(T v){ return *this= Mod(x*v); }
		Mod operator *=(Mod m){ return *this= Mod(x*m.x); }
		Mod operator /(T v) const{ //	フェルマーの小定理より, m.x の逆元は m.x^( HOU-2 )
			const T n= N-2; T r= x; for(T b= 1; b< n; b<<= 1){ if( n & b ) r= r*v%N; v= v*v%N; } return r; }
		Mod operator /(Mod m) const{ //	フェルマーの小定理より, m.x の逆元は m.x^( HOU-2 )
			const T n= N-2; T v= m.x, r= x; for(T b= 1; b< n; b<<= 1){ if( n & b ) r= r*v%N; v= v*v%N; } return r; }
		Mod operator /=(T v){ return *this= *this /v; }
		Mod operator /=(Mod m){ return *this= *this /m; }
		operator T() const{return x;}
		Mod(){}
		Mod(T v):x(v%N){}
	private:T x;}; Mod::T Mod::N= 1000 *1000 *1000 +7;
	//	最大値
	template <typename T> class Max{public:
		//	何回更新したか
		int cnt() const{return c;}

		//	更新したときに true を返す
		bool operator =(T v){if(!c){c=1;x=v;return true;}if(x<v){c++;x=v;return true;}return false;}

		operator T() const{return x;}
		Max():x(0),c(0){}
		Max(T v):x(v),c(1){}
		Max(const T*f,const T*l):x(*f++),c(1){while(f<l){*this=*f++;}}
		Max(const T*a,int n):x(0),c(0){For(i,n)*this=*a++;}
	private:T x;int c;};
	//	最小値
	template <typename T> class Min{public:
		//	何回更新したか
		int cnt() const{return c;}

		//	更新したときに true を返す
		bool operator =(T v){if(!c){c=1;x=v;return true;}if(v<x){c++;x=v;return true;}return false;}

		operator T() const{return x;}
		Min():x(0),c(0){}
		Min(T v):x(v),c(1){}
		Min(const T*f,const T*l):x(*f++),c(1){while(f<l){*this=*f++;}}
		Min(const T*a,int n):x(0),c(0){For(i,n)*this=*a++;}
	private:T x;int c;};
	istream& operator >>(istream&in,Mod&m){Mod::T t;in>>t;m=Mod(t);return in;}
	ostream& operator <<(ostream&ot,Mod m){return ot<<CAST(Mod::T,m);}
	template <typename T> istream& operator >>(istream&in,Max<T>&m){T t;in>>t;m=Max<T>(t);return in;}
	template <typename T> ostream& operator <<(ostream&ot,Max<T>m){return ot<<CAST(T,m);}
	template <typename T> istream& operator >>(istream&in,Min<T>&m){T t;in>>t;m=Min<T>(t);return in;}
	template <typename T> ostream& operator <<(ostream&ot,Min<T>m){return ot<<CAST(T,m);}
}
//	vec
namespace{
	//	2D int Vector
	class Pint{
	public:
		int x, y;
		static const Pint dir[8];

		//	util
		static void setup(int width, int height, int offset= -1, bool swap= false){ Width= width; Height= height; Offset= offset; Swap= swap; }
		inline bool isInFld() const{ return 0 <= x && x < Width && 0 <= y && y < Height; }

		//	vector
		inline double len() const{ return sqrt( sq() ); }
		inline double len(const Pint& p) const{ return sqrt( sq(p) ); }
		inline int sq() const{ return x*x+y*y; }
		inline int sq(const Pint& p) const{ return (x-p.x)*(x-p.x) +(y-p.y)*(y-p.y); }
		inline int manhattan() const{ return abs(x) +abs(y); }
		inline int manhattan(const Pint& p) const{ return abs(x-p.x) +abs(y-p.y); }
		inline int dot(const Pint& p) const{ return x*p.x+y*p.y; }
		inline int crs(const Pint& p) const{ return x*p.y-y*p.x; }

		//	opr, cst
		inline Pint operator +(){ return Pint( x, y ); }
		inline Pint operator -(){ return Pint( -x, -y ); }
		inline Pint operator +(const Pint& p) const{ return Pint( x+p.x, y+p.y ); }
		inline const Pint& operator +=(const Pint& p){ x+= p.x; y+= p.y; return *this; }
		inline Pint operator -(const Pint& p) const{ return Pint( x-p.x, y-p.y ); }
		inline const Pint& operator -=(const Pint& p){ x-= p.x; y-= p.y; return *this; }
		inline Pint operator *(const Pint& p) const{ return Pint( x*p.x, y*p.y ); }
		inline const Pint& operator *=(const Pint& p){ x*= p.x; y*= p.y; return *this; }
		inline Pint operator /(const Pint& p) const{ return Pint( x/p.x, y/p.y ); }
		inline const Pint& operator /=(const Pint& p){ x/= p.x; y/= p.y; return *this; }
		inline Pint operator *(const int k) const{ return Pint( x*k, y*k ); }
		inline const Pint& operator *=(const int k){ x*= k; y*= k; return *this; }
		inline Pint operator /(const int k) const{ return Pint( x/k, y/k ); }
		inline const Pint& operator /=(const int k){ x/= k; y/= k; return *this; }
		inline bool operator <(const Pint& p) const{ return x== p.x ? y<p.y : x<p.x; }
		inline bool operator >(const Pint& p) const{ return x== p.x ? y>p.y : x>p.x; }
		inline bool operator ==(const Pint& p) const{ return x==p.x && y==p.y; }
		inline bool operator !=(const Pint& p) const{ return x!=p.x || y!=p.y; }
		Pint(){}
		Pint(const int x, const int y) : x(x), y(y){}
		
	private:
		friend istream& operator >>(istream& in, Pint& p);
		friend ostream& operator <<(ostream& out, const Pint& p);
		static int Width, Height, Offset;
		static bool Swap;
	};
	istream& operator >>(istream& in, Pint& p){
		int x, y;
		in>> x>> y;
		x+= Pint::Offset;
		y+= Pint::Offset;
		if( Pint::Swap ) p= Pint( y, x );
		else p= Pint( x, y );
		return in;
	}
	ostream& operator <<(ostream& out, const Pint& p){
		return out<< "( "<< p.x<< ", "<< p.y<< " )";
	}
	int Pint::Width, Pint::Height, Pint::Offset; bool Pint::Swap;
	const Pint Pint::dir[8]= { Pint(0,1),Pint(1,0),Pint(0,-1),Pint(-1,0),Pint(1,1),Pint(1,-1),Pint(-1,1),Pint(-1,-1) };

	//	2D double Vector
	class Pdouble{
	public:
		double x, y;

		//	vector
		inline double len() const{ return sqrt( sq() ); }
		inline double len(const Pdouble& p) const{ return sqrt( sq(p) ); }
		inline double sq() const{ return x*x+y*y; }
		inline double sq(const Pdouble& p) const{ return (x-p.x)*(x-p.x) +(y-p.y)*(y-p.y); }
		inline Pdouble norm(const double l= 1.0){ return *this * l /len(); }
		inline double dot(const Pdouble& p) const{ return x*p.x+y*p.y; }
		inline double crs(const Pdouble& p) const{ return x*p.y-y*p.x; }
		inline Pdouble proj(const Pdouble& v) const{
			const double s= v.sq();
			if( s < EPS*EPS ) return Pdouble( 0, 0 );
			return v *dot( v ) /s;
		}
		inline Pdouble rot(const double rad) const{ const double c= cos( rad ), s= sin( rad ); return Pdouble( c*x-s*y, s*x+c*y ); }

		//	opr, cst
		inline Pdouble operator +(){ return Pdouble( x, y ); }
		inline Pdouble operator -(){ return Pdouble( -x, -y ); }
		inline Pdouble operator +(const Pdouble& p) const{ return Pdouble( x+p.x, y+p.y ); }
		inline const Pdouble& operator +=(const Pdouble& p){ x+= p.x; y+= p.y; return *this; }
		inline Pdouble operator -(const Pdouble& p) const{ return Pdouble( x-p.x, y-p.y ); }
		inline const Pdouble& operator -=(const Pdouble& p){ x-= p.x; y-= p.y; return *this; }
		inline Pdouble operator *(const Pdouble& p) const{ return Pdouble( x*p.x, y*p.y ); }
		inline const Pdouble& operator *=(const Pdouble& p){ x*= p.x; y*= p.y; return *this; }
		inline Pdouble operator /(const Pdouble& p) const{ return Pdouble( x/p.x, y/p.y ); }
		inline const Pdouble& operator /=(const Pdouble& p){ x/= p.x; y/= p.y; return *this; }
		inline Pdouble operator *(const double k) const{ return Pdouble( x*k, y*k ); }
		inline const Pdouble& operator *=(const double k){ x*= k; y*= k; return *this; }
		inline Pdouble operator /(const double k) const{ return Pdouble( x/k, y/k ); }
		inline const Pdouble& operator /=(const double k){ x/= k; y/= k; return *this; }
		inline bool operator <(const Pdouble& p) const{ return x== p.x ? y<p.y : x<p.x; }
		inline bool operator >(const Pdouble& p) const{ return x== p.x ? y>p.y : x>p.x; }
		inline bool operator ==(const Pdouble& p) const{ return x==p.x && y==p.y; }
		inline bool operator !=(const Pdouble& p) const{ return x!=p.x || y!=p.y; }
		Pdouble(){}
		Pdouble(const double x, const double y) : x(x), y(y){}
		Pdouble(const Pint& p) : x(p.x), y(p.y){}
	};
	istream& operator >>(istream& in, Pdouble& p){
		return in>> p.x>> p.y;
	}
	ostream& operator <<(ostream& out, const Pdouble& p){
		return out<< "( "<< p.x<< ", "<< p.y<< " )";
	}

	//	( lP, lQ ) と ( nP, nQ ) の線分の交差判定
	bool CollisionLine(const Pdouble lP, const Pdouble lQ, const Pdouble nP, const Pdouble nQ){
		auto sign= [](double d){ return d < 0 ? -1 : d > 0 ? 1 : 0; };
		Pdouble v= lQ-lP; if( sign( v.crs( nP -lP ) )== sign( v.crs( nQ -lQ ) ) ) return false;
		v= nQ -nP; return sign( v.crs( lP -nP ) ) * sign( v.crs( lQ -nP ) ) <= 0;
	}
}
//	util
namespace{
	void DoubleOut(double d, char c= '\n'){ printf("%.12f%c", d, c ); }
}

int main(){
	int N, M, K;
	cin>> N>> M>> K;

	Mod nm_2Ck_2;
	{
		Mod n= 1; ForA( i, 1, N*M -1 ) n*= i;
		Mod k= 1; ForA( i, 1, K -1 ) k*= i;
		Mod n_k= 1; ForA( i, 1, N*M -K +1 ) n_k*= i;
		nm_2Ck_2= n /( k *n_k );
	}

	Mod ans= 0;
	ForA( x, 1, N ){
		Mod t= x;
		t*= (N-x);
		t*= M;
		t*= M;
		t*= nm_2Ck_2;
		ans+= t;
	}
	ForA( y, 1, M ){
		Mod t= y;
		t*= (M-y);
		t*= N;
		t*= N;
		t*= nm_2Ck_2;
		ans+= t;
	}

	cout<< ans<< endl;

	return 0;
}
