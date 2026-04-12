#include <bits/stdc++.h>
#include <iomanip>
//#define DEBUG 1

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
#define UNQ(a) a.erase(std::unique(ALL(a)),a.end());
#define endl "\n"

const LD EPS=1e-5;
const long long INFLL=(LL)(1e9)*(LL)(1e9);
const int INF=1e9+7;

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

const LL powLL(const LL p, const LL q)
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

template<typename... Args>
void printd(const Args&... args)
{
	#ifdef DEBUG
		print(args...);
	#endif
}

template<typename Head>
void input(Head& head)
{
	cin>>head;
}

template<typename Head, typename... Tail>
void input(Head& head, Tail&... tail)
{
	cin>>head;
	input(tail...);
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
istream& operator >> (istream& is, pair<T, U>& t)
{
	is>>t.first>>t.second;
	return is;
}

template<int N, typename... Ts, typename enable_if<N == sizeof...(Ts)-1>::type*& = enabler>
void tuple_in(istream &is, tuple<Ts...> &t)
{
	is>>get<N>(t);
}
template<int N, typename... Ts, typename enable_if<N < sizeof...(Ts)-1>::type*& = enabler>
void tuple_in(istream &is, tuple<Ts...> &t)
{
	is>>get<N>(t);
	tuple_in<N+1, Ts...>(is, t);
}

template<typename... Ts>
istream& operator >> (istream& is, tuple<Ts...>& t)
{
	tuple_in<0, Ts...>(is, t);
	return is;
}


template<typename T, typename U>
ostream& operator << (ostream& os, const pair<T, U>& t)
{
	os<<'('<<t.first<<", "<<t.second<<')';
	return os;
}

template<int N, typename... Ts, typename enable_if<N == sizeof...(Ts)-1>::type*& = enabler>
void tuple_out(ostream &os,const tuple<Ts...> &t)
{
	os<<get<N>(t);
}
template<int N, typename... Ts, typename enable_if<N < sizeof...(Ts)-1>::type*& = enabler>
void tuple_out(ostream &os,const tuple<Ts...> &t)
{
	os<<get<N>(t)<<", ";
	tuple_out<N+1, Ts...>(os, t);
}

template<typename... Ts>
ostream& operator << (ostream& os, const tuple<Ts...>& t)
{
	os<<'(';
	tuple_out<0, Ts...>(os, t);
	os<<')';
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
	private:
		static const value_type MODULO = 1e9+7;
		value_type value;

		constexpr value_type Normalize(value_type x) const
		{
			return x<0?(x%MODULO+MODULO):(x%MODULO);
		}

	public:
		constexpr Mod():value(0){}
		constexpr Mod(const value_type &val):value(Normalize(val)) {}
		
		explicit operator value_type () const
		{
			return value;
		}

		constexpr const Mod operator -() const
		{
			return Mod(MODULO - value);
		}
		constexpr const Mod operator +(const Mod &rhs) const
		{
			return Mod(value + rhs.value);
		}
		constexpr const Mod operator -(const Mod &rhs) const
		{
			return Mod(value + (-rhs).value);
		}
		constexpr const Mod operator *(const Mod &rhs) const
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
		constexpr bool operator ==(const Mod &rhs)
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

/* verified AOJ Highway Express Bus
*使い方
Distを好きな辺のコストの型に置換する
Graph型変数vに辺の情報を与える
(v[a].push_back(PID(b,c))でaからbへコストcの有向辺を張る)
dijkstra(i,v):iから任意の点への最小コストのベクター
dijkstra(i,j,v):iからjへの最小コスト
dijkstra(i,j,v,path):iからjへの最小コスト+pathにiからjへの最小パス
dijkstra(i,v,preVec):iから任意の点への最小コストのベクター
get_path(i,j,preVec)でiからjへの最小パスが求まる
*/


#include <bits/stdc++.h>

using namespace std;

typedef LL Dist;

struct Edge;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct Edge
{
    int to;
    Dist dist;
    Edge(int to_, Dist dist_):to(to_),dist(dist_)
    {}
    bool operator >(const Edge &ed)const
    {
        return dist > ed.dist;
    }
};

//Shortest cost from i to j.
vector<Dist> dijkstra(int i, const Graph &vertex, vector<int> &preVector)
{
    vector<int> pVector(vertex.size(), INF);
    vector<Dist> shortest(vertex.size(), INFLL);
    priority_queue<Edge, vector<Edge>, greater<Edge> > que;

    que.push(Edge(i, 0));
    shortest[i]=0;

    Edge state(0,0), tmp(0,0), e(0,0);
    while(!que.empty())
    {
        state = que.top();
        que.pop();
        if(shortest[state.to] < state.dist) continue;
        for(Edge e : vertex[state.to])
        {
            if(shortest[e.to] > shortest[state.to] + e.dist)
            {
                shortest[e.to] = shortest[state.to] + e.dist;
                pVector[e.to] = state.to;
                tmp = Edge(e.to, shortest[e.to]);
                que.push(tmp);
            }
        }
    }
    preVector = pVector;
    return shortest;
}

vector<int> get_path(int i, int j, const vector<int> &preVector)
{
    vector<int> rev;
    rev.push_back(j);
    int p=j;
    while(p!=i)
    {
        p = preVector[p];
        rev.push_back(p);
        if(p==INF)
            return vector<int>();
    }
    reverse(rev.begin(),rev.end());
    return rev;
}

vector<Dist> dijkstra(int i, const Graph &vertex)
{
  vector<int> preVector(vertex.size());
  return dijkstra(i, vertex, preVector);
}
Dist dijkstra(int i,int j, const Graph &vertex)
{
  return dijkstra(i, vertex)[j];
}
Dist dijkstra(int i,int j, const Graph &vertex, vector<int> &path)
{
  vector<int> preVector(vertex.size());
  vector<Dist> shortest(dijkstra(i, vertex, preVector));
  path = get_path(i, j, preVector);
  return shortest[j];
}

int main()
{
	io_speedup();
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	s--;t--;
	Graph g(n), revg(n);
	REP(i,m)
	{
		int u,v;
		LL d;
		input(u,v,d);
		u--;
		v--;
		d*=2;
		g[u].push_back(Edge(v,d));
		g[v].push_back(Edge(u,d));
	}


	vector<Mod> pat(n);
	vector<Mod> pat2(n);
	pat[s]=1;
	pat2[t]=1;
	auto f=[&](int i, int j, const Graph &vertex)
	{
		vector<Dist> shortest(vertex.size(), INFLL);
		vector<Dist> shortest2(vertex.size(), INFLL);
		priority_queue<Edge, vector<Edge>, greater<Edge> > que;

		que.push(Edge(i, 0));
		shortest[i]=0;

		Edge state(0,0), tmp(0,0), e(0,0);

		while(!que.empty())
		{
			state = que.top();
			que.pop();
			if(shortest[state.to] < state.dist) continue;
			for(Edge e : vertex[state.to])
			{
				if(shortest[e.to] > shortest[state.to] + e.dist)
				{
					shortest[e.to] = shortest[state.to] + e.dist;
					tmp = Edge(e.to, shortest[e.to]);
					que.push(tmp);
					pat[e.to]=pat[state.to];
				}
				else if(shortest[e.to] == shortest[state.to] + e.dist)
				{
					pat[e.to]+=pat[state.to];
				}
			}
		}

		Graph g2(n);
		VB reach(n);
		que.push(Edge(j,-shortest[j]));
		while(!que.empty())
		{
			state = que.top();
			que.pop();
			if(reach[state.to]) continue;
			reach[state.to]=1;
			for(Edge e : vertex[state.to])
			{
				if(shortest[state.to] == shortest[e.to] + e.dist)
				{
					g2[e.to].push_back(Edge(state.to, e.dist));
					g2[state.to].push_back(Edge(e.to, e.dist));
					que.push(Edge(e.to, -shortest[e.to]));
					pat2[e.to]+=pat2[state.to];
				}
			}
		}
		return make_tuple(shortest, g2);
	};
	VLL stt;
	Graph g2;

	tie(stt,g2)=f(s,t,g);
	LL sd=stt[t];
	sd/=2;

	Mod ans=0,sum=0;
	ans=pat[t]*pat[t];
	REP(i,n)
	{
		for(auto&& e:g2[i])
		{
			if(stt[i]<sd&&sd<stt[e.to])
			{
				sum+=pat[i]*pat[i]*pat2[e.to]*pat2[e.to];
				printd("edge",i,e.to,pat[i]);
			}
		}
		if(stt[i]==sd)
		{
			sum+=pat[i]*pat[i]*pat2[i]*pat2[i];
			printd("vert",i,pat[i]);
		}
	}

	print(ans-sum);
}