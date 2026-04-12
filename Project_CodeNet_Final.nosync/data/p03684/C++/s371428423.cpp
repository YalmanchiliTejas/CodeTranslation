#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <iomanip>
#include<numeric>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
const long long INF = 1LL << 60;
ll mod=1e9+7;
using namespace std;
int n;
int X[100010]; int Y[100010];
vector<pair<int,int> > XX;
vector<pair<int,int> > YY;
vector<pair<int,pair<int,int> > > XY;
class UnionFind{
public:
	vector<int> par,num;

	int find(int v){
		return (par[v]==v)? v: (par[v]=find(par[v]));
	}
	explicit UnionFind(int N):par(N),num(N,1){
		iota(par.begin(),par.end(),0);
	}
	void unite(int u,int v){
		u=find(u),v=find(v);
		if(u==v)return ;
		if(num[u]<num[v])swap(u,v);
		num[u] += num[v];
		par[v] = u;
	}
	bool same(int u,int v){
		return find(u) == find(v);
	}
	bool ispar(int v){
		return v=find(v);
	}
	int size(int v){
		return num[find(v)];
	}
};
int main(){
	cin >>n;
	UnionFind uf(n);
	for(int i=0;i<n;i++){
		cin >> X[i] >> Y[i];
		XX.push_back(make_pair(X[i],i));
		YY.push_back(make_pair(Y[i],i));
	}
	sort(XX.begin(),XX.end());
	sort(YY.begin(),YY.end());
	for(int j=0;j<n-1;j++){
		XY.push_back(make_pair(XX[j+1].first-XX[j].first,make_pair(XX[j+1].second,XX[j].second)));
		XY.push_back(make_pair(YY[j+1].first-YY[j].first,make_pair(YY[j+1].second,YY[j].second)));
	}
	ll cnt=0;
	sort(XY.begin(),XY.end());
	for(auto e:XY){
		if(!uf.same(e.second.first,e.second.second)){
			uf.unite(e.second.first,e.second.second);
			cnt+=e.first;
		}
	}
	cout << cnt << endl;
}