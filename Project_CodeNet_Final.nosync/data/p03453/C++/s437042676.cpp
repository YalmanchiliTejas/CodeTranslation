// #includes {{{
#include <bits/stdc++.h>
using namespace std;

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
#define debug_v(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

template<class T>
T inf(){
	return numeric_limits<T>::has_infinity?numeric_limits<T>::infinity():(numeric_limits<T>::max()/2);
}

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

//{{{ io
FILE *file_in=stdin,*file_out=stdout;
#define fin normal_in
#define fout normal_out
//const char fname[]="";
//FILE *fin=fopen(fname,"r"),*fout=fopen(fname,"w");
#ifdef __MINGW32__
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif
struct NORMAL_IN{
	bool cnt;
	NORMAL_IN():cnt(true){}
	operator int() const {return cnt;}
#define endl "\n"
	NORMAL_IN& operator>>(int &n){cnt=fscanf(file_in,"%d",&n)!=EOF;return *this;}
	NORMAL_IN& operator>>(unsigned int &n){cnt=fscanf(file_in,"%u",&n)!=EOF;return *this;}
	NORMAL_IN& operator>>(long long &n){cnt=fscanf(file_in,LLD,&n)!=EOF;return *this;}
	NORMAL_IN& operator>>(unsigned long long &n){cnt=fscanf(file_in,LLU,&n)!=EOF;return *this;}
	NORMAL_IN& operator>>(double &n){cnt=fscanf(file_in,"%lf",&n)!=EOF;return *this;}
	NORMAL_IN& operator>>(long double &n){cnt=fscanf(file_in,"%Lf",&n)!=EOF;return *this;}
	NORMAL_IN& operator>>(char *c){cnt=fscanf(file_in,"%s",c)!=EOF;return *this;}
	NORMAL_IN& operator>>(string &s){
		s.clear();
		for(bool r=false;;){
			const char c=getchar();
			if(c==EOF){ cnt=false; break;}
			const int t=isspace(c);
			if(!r and !t)r=true;
			if(r){
				if(!t)s.push_back(c);
				else break;
			}
		}
		return *this;
	}
	template<class T>
		NORMAL_IN& operator>>(vector<T> &v){
			int n;fscanf(file_in,"%d",&n);
			REP(i,n){
				T t;*this>>t;
				v.push_back(t);
			}
			return *this;
		}
} normal_in;

struct NORMAL_OUT{
	NORMAL_OUT& operator<<(const int &n){fprintf(file_out,"%d",n);return *this;}
	NORMAL_OUT& operator<<(const unsigned int &n){fprintf(file_out,"%u",n);return *this;}
	NORMAL_OUT& operator<<(const long long &n){fprintf(file_out,LLD,n);return *this;}
	NORMAL_OUT& operator<<(const unsigned long long &n){fprintf(file_out,LLU,n);return *this;}
	NORMAL_OUT& operator<<(const double &n){fprintf(file_out,"%lf",n);return *this;}
	NORMAL_OUT& operator<<(const long double &n){fprintf(file_out,"%Lf",n);return *this;}
	NORMAL_OUT& operator<<(const char c[]){fprintf(file_out,"%s",c);return *this;}
	NORMAL_OUT& operator<<(const string &s){fprintf(file_out,"%s",s.c_str());return *this;}
} normal_out;
struct ERR_OUT{
	template<class T>
		ERR_OUT& operator<<(const T &a){
			cerr<<"\x1b[7m"<<a<<"\x1b[m";
			return *this;
		}
} ferr;
//}}}

//{{{ Graph<Weight> g(size); addEdge(g,{src,dst},weight); matrix<Weight> A(n,m);
//typedef int Node;
template<class Weight>
struct edge {
	int src, dst;
	Weight weight;
	int rev;
	edge(int src, int dst, Weight weight=1,int rev=-1) :
		src(src), dst(dst), weight(weight), rev(rev){ }
};
template<class Weight>
bool operator < (const edge<Weight> &e, const edge<Weight> &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
		e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
//typedef vector<edge> edges;
//typedef vector<edges> Graph;
 
template<class Weight>
struct matrix:vector<vector<Weight> >{
	matrix(const array<int,2> &a, Weight w=0):vector<vector<Weight> >(a[0],vector<Weight>(a[1],w)){}
	matrix(const array<int,1> &a, Weight w=0):vector<vector<Weight> >(a[0],vector<Weight>(a[0],0)){}
	matrix(){}
};
 
template<class Weight>
struct graph:vector<vector<edge<Weight> > >{
	Weight inf{::inf<Weight>()};
	graph(){}
	graph(const int &n):vector<vector<edge<Weight> > >(n){}
	void _add_edge(int from, int to, Weight w, int rev=-1){
		if((int)this->size() < from + 1)this->resize(from + 1);
		this->at(from).push_back(edge<Weight>(from,to,w,rev));
	}
};
//add bi-directional edge
template<class Weight>
void addBiEdge(graph<Weight> &g, const pair<int,int> &e, Weight w=1){
	const int &from = e.first, &to = e.second;
	g._add_edge(from,to,w,g[to].size());
	g._add_edge(to,from,w,g[from].size()-1);
}
//add directional edge
template<class Weight>
void addEdge(graph<Weight> &g, const pair<int,int> &e, Weight w=1){
	const int &from = e.first, &to = e.second;
	g._add_edge(from,to,w);
}
 
//typedef int Weight;
/*
typedef long long Weight;
typedef edge<Weight> Edge;
typedef graph<Weight> Graph;
typedef matrix<Weight> Matrix;
*/
 
#ifdef DEBUG
#include"graph/graphviz.h"
#endif
//}}}


const int mod = 1000000007;
//{{{ modular algebra
template<int mod>
struct Num{
	int v;
	Num(int n):v(n){}
	Num():v(0){}
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

typedef Num<1000000007> mod_int;

template<int mod>
ostream& operator <<(ostream &os,const Num<mod> &n){
	os<<(int)n.v;
	return os;
}

template<int mod>
istream& operator >>(istream &is, Num<mod> &n){
	is>>n.v;
	return is;
}
//}}}

//{{{ shortest_path(graph g, int s) : Dijkstra
template<class Weight>
struct dijkstra_t{
	vector<mod_int> dp;
	const graph<Weight> &g;
	const int &s;
	vector<Weight> dist;
	vector<int> prev;
//	dijkstra_t(const graph<Weight> &g,int s):g(g),s(s),dist(g.size(),g.inf),prev(g.size(),-1){}
	dijkstra_t(const graph<Weight> &g,int s):g(g),s(s),dist(g.size(),g.inf),prev(g.size(),-1){
		/*
		assert(dist.size()==g.size());
		REP(i,dist.size())assert(dist[i]>=0 and dist[i]+dist[i]>=0);
		*/
	}
	vector<int> path(int t) {
		vector<int> path;
		for (int u = t; u >= 0; u = prev[u])path.push_back(u);
		reverse(ALL(path));
		return path;
	}
	void dijkstra(){
		dist[s] = 0;
		priority_queue<edge<Weight> > Q; // "e < f" <=> "e.weight > f.weight"
		for (Q.push(edge<Weight>(-2, s, 0)); !Q.empty(); ) {
			edge<Weight> e = Q.top(); Q.pop();
			if (prev[e.dst] != -1) continue;
			prev[e.dst] = e.src;
			for(auto f:g[e.dst]) {
//				assert(e.weight<=g.inf);
//				assert(0<=f.weight and f.weight<=g.inf);
				Weight w = e.weight + f.weight;
				if (dist[f.dst] > w) {
					dist[f.dst] = w;
					Q.push(edge<Weight>(f.src, f.dst, w));
				}
			}
		}
	}
	void count_dp(){
		vector<pair<Weight,int> > d;
		REP(u,g.size())d.push_back({dist[u],u});
		sort(ALL(d));
		dp.assign(g.size(),mod_int());
		dp[s] = 1;
		REP(i,d.size()){
			int u = d[i].second;
			for(auto &&e:g[u]){
				if(dist[e.dst]+e.weight==dist[u]){
					dp[u]+=dp[e.dst];
				}
			}
		}
	}
};
template<class Weight>
dijkstra_t<Weight> shortest_path(const graph<Weight> &g, int s) {
	dijkstra_t<Weight> ret(g,s);
	ret.dijkstra();
	ret.count_dp();
	return ret;
}
//}}}

void solve(long long N, long long M, long long S, long long T, vector<long long> U, vector<long long> V, vector<long long> D){
	graph<long long> g(N),h;
	REP(i,M){
		addBiEdge(g,{U[i],V[i]},D[i]);
	}
	auto gs = shortest_path(g,S);
	h = g;
	auto hs = shortest_path(h,T);
	long long d = gs.dist[T];
//	assert(d>=0);
	mod_int ans = gs.dp[T]*gs.dp[T];
	if(d%2==0){
		long long t = d/2;
		REP(u,N){
			if(gs.dist[u]!=t or hs.dist[u]!=t)continue;
			ans -= gs.dp[u]*gs.dp[u]*hs.dp[u]*hs.dp[u];
		}
	}
	REP(u,N){
		for(auto &&e:g[u]){
			int v = e.dst;
			long long w = e.weight;
			if(gs.dist[u]+w+hs.dist[v]!=d)continue;
			if(gs.dist[u]+w!=gs.dist[v])continue;
			if(hs.dist[v]+w!=hs.dist[u])continue;
			if(gs.dist[u]<gs.dist[v] and gs.dist[u]*2<d and d<gs.dist[v]*2){
				ans -= gs.dp[u]*gs.dp[u]*hs.dp[v]*hs.dp[v];
			}
		}
	}
	fout<<(int)ans<<endl;
}

int main(){	
	long long N;
	long long S;
	long long T;
	long long M;
	fin >> N;
	fin >> M;
	vector<long long> U(M-1+1);
	vector<long long> V(M-1+1);
	vector<long long> D(M-1+1);
	fin >> S;
	fin >> T;
	S--;T--;
	for(int i = 0 ; i <= M-1 ; i++){
		fin >> U[i];
		fin >> V[i];
		U[i]--;V[i]--;
		fin >> D[i];
	}
	solve(N, M, S, T, U, V, D);
	return 0;
}
