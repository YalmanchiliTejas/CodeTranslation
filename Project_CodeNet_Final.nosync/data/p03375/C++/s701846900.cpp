#include <bits/stdc++.h>
#include <iomanip>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PLDLD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VB;
 
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define endl "\n"
 
const LD eps=1e-10;
const long long INFLL=(LL)(1e9)*(LL)(1e9);
const int INF=1e9;
 
template<class T>
void chmin(T& a, const T b)
{
	if(a>b)
		a=b;
}
template<class T>
void chmax(T& a, const T b)
{
	if(a<b)
		a=b;
}
 
const LL pow(const LL p, const LL q)
{
	LL t=1;
	for(int i=0;i<q;i++)
		t*=p;
	return t;
}

template <typename T>
struct has_iter
{
	private:
		template <typename U>
		static constexpr true_type check(typename U::iterator*);
		template <typename U>
		static constexpr false_type check(...);

	public:
		static constexpr bool value = decltype(check<T>(nullptr))::value;
};


template<typename T, typename U = typename T::iterator>
void print(const T& container)
{
		auto&& first=begin(container), last=end(container);
		auto&& back=prev(last);
		for(auto e=first; e!=last; e=next(e))
			cout<<*e<<" \n"[e==back];
}


extern void* enabler;
template<typename Head, typename enable_if<!has_iter<Head>::value>::type*& = enabler>
void print(const Head& head)
{
	cout<<head<<endl;
}

template<> void print<string>(const string& container)
{
	cout<<container<<endl;
}

template<typename Head, typename... Tail>
void print(const Head& head, const Tail&... tail)
{
	cout<<head<<" ";
	print(tail...);
}

void io_speedup()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
}

template<typename T>
istream& operator >> (istream& is, vector<T>& vec)
{
	for(T& x: vec) is >> x;
	return is;
}


template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& p)
{
	os<<'('<<p.first<<", "<<p.second<<')';
	return os;
}

template<typename T>
vector<T> read(int n)
{
	vector<T> t(n);
	cin>>t;
	return t;
}

template<typename T>
T read()
{
	T t;
	cin>>t;
	return t;
}

template<typename Head, typename... Tail>
struct vector_demensions
{
	using type=vector<typename vector_demensions<Tail...>::type>;
};

template<typename Head>
struct vector_demensions<Head> { using type=Head; };

template<typename T>
vector<T> make_vectors(int size, T val)
{
	return vector<T>(size, val);
}

template<typename T=int, typename... Args>
auto make_vectors(int size, Args... tail)
	-> typename vector_demensions<Args..., T>::type
{
	auto val=make_vectors<T>(forward<Args>(tail)...);
	return vector<decltype(val)>(size, val);
}


class Mod
{
	public:
		using value_type = long long;
		static value_type MODULO;
	private:
		value_type value;

		value_type Normalize(value_type x) const
		{
			return x<0?(x%MODULO+MODULO):(x%MODULO);
		}

	public:
		Mod():value(0){}
		Mod(const value_type &val):value(Normalize(val)) {}
		
		explicit operator value_type () const
		{
			return value;
		}

		const Mod operator -() const
		{
			return Mod(MODULO - value);
		}
		const Mod operator +(const Mod &rhs) const
		{
			return Mod(value + rhs.value);
		}
		const Mod operator -(const Mod &rhs) const
		{
			return Mod(value + (-rhs).value);
		}
		const Mod operator *(const Mod &rhs) const
		{
			return Mod(value * rhs.value);
		}
		Mod &operator +=(const Mod &rhs)
		{
			return *this = *this + rhs;
		}
		Mod &operator -=(const Mod &rhs)
		{
			return *this = *this - rhs;
		}
		Mod &operator *=(const Mod &rhs)
		{
			return *this = *this * rhs;
		}


		Mod pow(value_type p) const;

		Mod inv() const
		{
			return pow(MODULO-2);
		}

		const Mod operator /(const Mod &rhs) const
		{
			return *this * rhs.inv();
		}
		Mod &operator /=(const Mod &rhs)
		{
			return *this = *this / rhs;
		}  
		bool operator ==(const Mod &rhs)
		{
			return value == rhs.value;
		}
};

Mod Mod::pow(value_type p) const
{
	Mod tmp=1, mult=*this;
	while(p)
	{
		if((p&1)>0) tmp*=mult;
		p>>=1;
		mult*=mult;
	}
	return tmp;
}

namespace std
{
	ostream& operator<<(ostream& os, const Mod mod)
	{
		os<<(typename Mod::value_type)mod;
		return os;
	}
};

class Factorial
{
	private:
		vector<Mod> ary;
	public:
		explicit Factorial(const size_t size):ary(vector<Mod>(size))
		{
			ary[0]=1;
			for(size_t i=1;i<size;i++)
				ary[i]=ary[i-1]*i;
		}

		size_t size() const {   return ary.size();  }

		Mod operator[] (const int id) const
		{
			return ary[id];
		}
};
class FactorialInv
{
	private:
		vector<Mod> ary;
	public:
		explicit FactorialInv(const Factorial &fact):ary(vector<Mod>(fact.size()))
		{
			for(size_t i=0;i<ary.size();i++)
				ary[i]=fact[i].inv();
		}

		//FactorialInv& operator=(FactorialInv&&)=default;

		Mod operator[] (const int id) const
		{
			return ary[id];
		}
};

class Combination
{
	private:
		const Factorial *fact;
		const FactorialInv *fact_inv;
	public:
		Combination(const Factorial &fact_, const FactorialInv &fact_inv_):fact(&fact_),fact_inv(&fact_inv_)
		{}

		Mod operator()(const int n, const int m) const
		{
			return (*fact)[n] * (*fact_inv)[m] * (*fact_inv)[n-m];
		}
};

Mod::value_type Mod::MODULO=1e9+7;

int main()
{
	int n,m;
	cin>>n>>m;
	Mod::MODULO=m;
	const int N=100000, NN=3000*3000+1;
	Factorial fa(N);
	FactorialInv fi(fa);
	Combination comb(fa,fi);
	vector<Mod> ppw(N), pw(NN);
	ppw[0]=2;
	REP(i,N-1)
		ppw[i+1]=ppw[i]*ppw[i];
	pw[0]=1;
	REP(i,NN-1)
		pw[i+1]=pw[i]*2;
	//starling
	vector<vector<Mod>> str(n+1, vector<Mod>(n+1));
	str[0][0]=1;
	str[1][0]=1;
	str[1][1]=1;
	FOR(i,2,n+1)
	{
		str[i][0]=1;
		FOR(j,1,i+1)
		{
			str[i][j]=str[i-1][j-1]+Mod(j+1)*str[i-1][j];
		}
	}
	vector<Mod> s(n+1);
	REP(i,n+1)
	REP(j,n+1)
	{
		s[i]+=str[i][j]*pw[(n-i)*j]*ppw[n-i];
	}
	//print(s);
	Mod ans=0;
	FOR(i,0,n+1)
	{
		ans+=Mod(i%2==1?-1:1)*comb(n,i)*s[i];
	}
	print(ans);
}
