#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
 
using namespace std; 

using namespace std;
 
typedef long long LL;
 
typedef pair<LL,LL> p;
typedef pair<LL,p> pp;

 
template <typename T>
class UF{
public:
	vector<T> par,rank;
 
	UF(T n){
		par.resize(n);
		rank.resize(n);
		for(T i=0;i<n;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
 
	T find(T x){
		if(par[x]==x)
			return x;
		else
			return par[x]=find(par[x]);
	}
 
	bool unite(T x, T y){
		x=find(x);
		y=find(y);
		if(x==y) return false;
 
		if(rank[x]<rank[y])
			par[x]=y;
		else{
			par[y]=x;
			if(rank[x] == rank[y]) rank[y]++;
		}

		return true;
	}
 
	bool same(T x, T y){
		return find(x)==find(y);
	}
 
};

int main(){

	int n;
	cin>>n;

	vector<long long> x(n),y(n);
	vector< p > xi(n),yi(n);
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		x[i]--,y[i]--;
		xi[i]=p(x[i],i);
		yi[i]=p(y[i],i);
	}

	sort(xi.begin(),xi.end());
	sort(yi.begin(),yi.end());

	vector<pp> edge;
	for(int i=0;i<n-1;i++){
		int from=xi[i].second;
		int to=xi[i+1].second;
		long long cost = min( abs(x[from]-x[to]),abs(y[from]-y[to]) );
		edge.push_back( pp(cost,p(from,to) ));
	}

	for(int i=0;i<n-1;i++){
		int from=yi[i].second;
		int to=yi[i+1].second;
		long long cost = min( abs(x[from]-x[to]),abs(y[from]-y[to]) );
		edge.push_back( pp(cost,p(from,to) ));
	}

	sort(edge.begin(),edge.end());

	UF<long long> uf(n);
	long long res=0;
	for(int i=0;i<edge.size();i++){

		int from=edge[i].second.first;
		int to=edge[i].second.second;
		long long cost=edge[i].first;

		if( uf.unite(from,to) )	res+=cost;

	}
	//cout<<uf.same(0,1)<<uf.same(1,2)<<uf.same(0,2)<<endl;
	cout<<res<<endl;

	return 0;
}
