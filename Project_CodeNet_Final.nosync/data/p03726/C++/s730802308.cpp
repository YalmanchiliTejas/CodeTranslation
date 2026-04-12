#include <cassert>// c
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
#include <random>
#include <regex>
using namespace std;

typedef long long ll;typedef unsigned long long ull;typedef long double ld;

#define ALL(c) c.begin(),c.end()
#define IN(l,v,r) (l<=v && v < r)
template<class T> void UNIQUE(T& v){v.erase(unique(ALL(v)),v.end());}
//debug
#define DUMP(x) cerr << #x <<" = " << (x)
#define LINE() cerr<< " (L" << __LINE__ << ")"

struct range{
	struct Iter{
		int v,step;
		Iter& operator++(){v+=step;return *this;}
		bool operator!=(Iter& itr){return v<itr.v;}
		int& operator*(){return v;}
	};
	Iter i, n;
	range(int i, int n,int step):i({i,step}), n({n,step}){}
	range(int i, int n):range(i,n,1){}
	range(int n):range(0,n){}
	Iter& begin(){return i;}
	Iter& end(){return n;}
};
struct rrange{
	struct Iter{
		int v,step;
		Iter& operator++(){v-=step;return *this;}
		bool operator!=(Iter& itr){return v>itr.v;}
		int& operator*(){return v;}
	};
	Iter i, n;
	rrange(int i, int n,int step):i({i-1,step}), n({n-1,step}){}
	rrange(int i, int n):rrange(i,n,1){}
	rrange(int n) :rrange(0,n){}
	Iter& begin(){return n;}
	Iter& end(){return i;}
};

//input
template<typename T1,typename T2> istream& operator >> (istream& is,pair<T1,T2>& p){return is>>p.first>>p.second;}
template<typename T1> istream& operator >> (istream& is,tuple<T1>& t){return is >> get<0>(t);}
template<typename T1,typename T2> istream& operator >> (istream& is,tuple<T1,T2>& t){return is >> get<0>(t) >> get<1>(t);}
template<typename T1,typename T2,typename T3> istream& operator >> (istream& is,tuple<T1,T2,T3>& t){return is >>get<0>(t)>>get<1>(t)>>get<2>(t);}
template<typename T1,typename T2,typename T3,typename T4> istream& operator >> (istream& is,tuple<T1,T2,T3,T4>& t){return is >> get<0>(t)>>get<1>(t)>>get<2>(t)>>get<3>(t);}
template<typename T> istream& operator >> (istream& is,vector<T>& as){for(int i:range(as.size()))is >>as[i];return is;}
//output
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){return os<<p.first<<" "<<p.second;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){return os << get<0>(t);}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){return os << get<0>(t)<<" "<<get<1>(t);}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){return os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);}
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){for(int i:range(as.size())){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& as){for(int i:range(as.size())){if(i!=0)os<<endl; os<<as[i];}return os;}

// values
template<typename T> inline T INF(){assert(false);};
template<> inline int INF<int>(){return 1<<28;};
template<> inline ll INF<ll>(){return 1LL<<58;};
template<> inline double INF<double>(){return 1e16;};
template<> inline long double INF<long double>(){return 1e16;};

template<class T> inline T EPS(){assert(false);};
template<> inline int EPS<int>(){return 1;};
template<> inline ll EPS<ll>(){return 1LL;};
template<> inline double EPS<double>(){return 1e-8;};
template<> inline long double EPS<long double>(){return 1e-8;};

// min{2^r | n < 2^r}
template<typename T> T upper_pow2(T n){ T res=1;while(res<n)res<<=1;return res;}
// max{d | 2^d  <= n}
template<typename T> T msb(T n){ int d=62;while((1LL<<d)>n)d--;return d;}

template<typename T,typename U> T pmod(T v,U M){return (v%M+M)%M;}



template<class Cost> struct Edge{
    int to;Cost cost;
    Edge(int to,Cost cost):to(to),cost(cost){};
    bool operator<(Edge r) const{ return cost<r.cost;}
    bool operator>(Edge r) const{ return cost>r.cost;}
};
template<class Cost> ostream& operator << (ostream& os, const Edge<Cost>& e){ return os<<"(->"<<e.to <<","<<e.cost<<")";}
template<class Cost> using Graph = vector<vector<Edge<Cost>>>;

template<class Cost> vector<Cost> dijkstra(const Graph<Cost>& g,const int s){
    vector<Cost> ds(g.size(),INF<Cost>());ds[s]=0;
    priority_queue<pair<Cost,int>,vector<pair<Cost,int>>,greater<pair<Cost,int>>> que;que.push({0,s});
    while(!que.empty()){
        Cost c;int v;tie(c,v)=que.top();que.pop();
        for(const Edge<Cost>& e:g[v]){
            Cost nxtc= c + e.cost;
            if(nxtc<ds[e.to]){
                ds[e.to]=nxtc;
                que.push({nxtc,e.to});
            }
        }
    }
    return ds;
}


class Main{
	public:

	void run(){
		int N;cin >> N;
		Graph<ll> g(N);
		for(int i:range(N-1)){
			int a,b;cin >> a >> b;a--;b--;
			g[a].push_back({b,1});
			g[b].push_back({a,1});
		}

		vector<bool> used(N); queue<int> que;
		for(int i:range(N))if(g[i].size()==1){
			que.push(i);
		}

		vector<int> inc(N);
		while(!que.empty()){
			int i = que.front();que.pop();
			// unique
			for(auto e:g[i])if(!used[e.to] && !used[i]){
				used[i] = used[e.to] = true;
				for(auto e2:g[e.to])if(!used[e2.to]){
					inc[e2.to]++;
					if(inc[e2.to] == g[e2.to].size()-1){
						que.push(e2.to);
					}
				}
			}
		}
	
		bool ok = true;
		for(int i:range(N)) ok &= used[i];

		if(!ok){
			cout << "First" << endl;
		}else{
			cout << "Second" << endl;
		}
	}
};

int main(){
	cout <<fixed<<setprecision(20);
	cin.tie(0);
	ios::sync_with_stdio(false);
	Main().run();
	return 0;
}
