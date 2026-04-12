// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

//{{{ gcd and inverse
#define __GCD_H
Int gcd(Int a, Int b) {
	return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
	return a / gcd(a, b) *b;
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
	Int g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}
Int invMod(Int a, Int m) {
	Int x, y;
	if (extgcd(a, m, x, y) == 1) return (x + m) % m;
	else                         return 0; // unsolvable
}
//}}}

const int mod = 1000000007;

//{{{ modular algebra
struct Num{
	int v;
	Num(int n):v(n){}
	Num(){}
	operator int() const {return v;}
	operator long long() const {return v;}
	void operator =(int n){v=n;}

	template<class T>
		inline void operator *=(const T &a) {
			v = (v*(long long)a)%mod;
		}
	template<class T>
		inline Num operator *(const T &a) {
			Num n(*this);n*=a;
			return n;
		}
	template<class T>
		inline void operator+=(const T &a){
			v+=(int)a;
			if(v>=mod)v-=mod;
			//	assert(0<=v and v<mod);
		}
	template<class T>
		inline Num operator+(const T &a){
			Num n(*this);n+=a;
			return n;
		}
	inline Num operator -(){
		if(v==0)return v;
		else return Num(mod-v);
	}
	template<class T>
		inline void operator -=(const T &a){
			v-=(int)a;
			if(v<0)v+=mod;
		}
	template<class T>
		inline Num operator -(const T &a){
			Num n(*this);n-=a;
			return n;
		}
#ifdef __GCD_H
	inline Num inv(){
		return invMod(this->v,mod);
	}
	template<class T>
		inline void operator /=(const T &a){
			(*this)*=invMod((int)a,mod);
		}
	template<class T>
		inline Num operator /(const T &a){
			Num n(*this);n/=a;
			return n;
		}
#endif
};

ostream& operator <<(ostream &os,const Num &n){
	os<<(int)n.v;
	return os;
}

istream& operator >>(istream &is, const Num &n){
	is>>(int)n.v;
	return is;
}
//}}}

//{{{ fact, binom, multinom
inline Num fact(int n,const int &mod = mod){
	static vector<Num> __fact(1,1);
	while(n>=__fact.size())__fact.push_back(__fact.back()*__fact.size());
	return __fact[n];
}
#ifdef __GCD_H
inline Num binom(int n,int r){
	if(n<0 or r<0 or n<r)return 0;
	return fact(n)/(fact(r)*fact(n-r));
}

inline Num multinom(const vector<int> &v){
	Num num(fact(accumulate(ALL(v),0))), denom(1);
	REP(i,v.size())denom*=fact(v[i]);
	return num/denom;
}
#endif
//}}}

//{{{ pow

/* (x^k)%m */
inline Num pow(Num x, int k){
	if(k==0) return 1;
	Num res(pow(x,k/2));
	res*=res;
	if(k%2)res*=x;
	return res;
}
//}}}
//残り人数, グループサイズ

int N,A,B,C,D;

int dp[1010][1010];

Num calc(int i,int j){
	if(dp[i][j]>=0)return dp[i][j];
	if(i==0)return dp[i][j] = 1;
	if(j>B)return dp[i][j] = 0;
	Num ans = 0;
	for(int F = C;F<=D;F++){
		int i2 = i-F*j;
		if(i2<0)break;
		ans+=calc(i2,j+1)*fact(i)*fact(F*j)/(pow(fact(j),F)*fact(F)*fact(i2)*fact(i-i2));
	}
	ans+=calc(i,j+1);
	return dp[i][j] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>N>>A>>B>>C>>D;
	cout<<calc(N,A)<<endl;
	return 0;
}
