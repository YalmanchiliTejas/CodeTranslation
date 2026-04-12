//spnauT
#include <bits/stdc++.h>
#define FOR(i,a,b) for(int _=b,i=a;i<_;++i)
#define ROF(i,b,a) for(int _=a,i=b;i>_;--i)
#define REP(n) for(int _=(n);_--;)
#define _1 first
#define _2 second
#define PB push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue<T>
#define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
#define IO {ios_base::sync_with_stdio(0);cin.tie(0);}
#define nl '\n'
#define cint1(a) int a;cin>>a
#define cint2(a,b) int a,b;cin>>a>>b
#define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
using namespace std;using LL=int64_t;using PII=pair<int,int>;
using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}

class UnionFind
{
private:
	int N; VP par_sz;
public:
	UnionFind(int n = 0) noexcept {resize(n);}
	void resize(int n) noexcept {N = n; par_sz.resize(N); reset();}
	void reset() noexcept {FOR(i,0,N) par_sz[i] = {i,1};}
	int findSet(int a) noexcept
	{
		if(par_sz[a]._1 != a)
			par_sz[a]._1 = findSet(par_sz[a]._1);
		return par_sz[a]._1;
	}
	int unionSet(int a, int b) noexcept
	{
		a = findSet(a); b = findSet(b);
		if(a == b) return 0;
		if(par_sz[a]._2 < par_sz[b]._2) swap(a,b);
		par_sz[a]._2 += par_sz[b]._2;
		par_sz[b]._1 = par_sz[a]._1;
		return 1;
	}
};

const int MAX_N {100005};

int X[MAX_N];
int Y[MAX_N];

int main()
{
	IO;
	cint1(N);
	FOR(i,0,N) cin >> X[i] >> Y[i];

	auto dist = [&](int a, int b)
	{
		return min(abs(X[a] - X[b]), abs(Y[a] - Y[b]));
	};
	using T3 = tuple<int,int,int>;
	MIN_PQ(T3) Q;
	VI A(N);

	auto f = [&](auto func)
	{
		iota(ALL(A),0);
		sort(ALL(A), func);
		FOR(i,1,N) Q.emplace(dist(A[i-1], A[i]), A[i-1], A[i]);
	};
	f([&](int a, int b) {return X[a] < X[b];});
	f([&](int a, int b) {return Y[a] < Y[b];});

	UnionFind U(N);
	int sol {0};
	while(not Q.empty())
	{
		int d, a, b;
		tie(d,a,b) = Q.top();
		Q.pop();

		if(U.unionSet(a,b)) sol += d;
	}
	cout << sol << nl;

	return 0;
}