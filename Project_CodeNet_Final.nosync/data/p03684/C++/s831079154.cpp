/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<int,ii> iii2;
typedef pair<double,int> di;
typedef pair<ii,ii> iiii;
long long mod = 1000000007LL;
long long base = 37;
long long large = 1000000000000000000LL;

class UnionFind {
	private: vector<int> p,rank;
	public:
	UnionFind(int n){
		rank.assign(n,0);
		p.assign(n,0);
		for(int i=0;i<n;i++){
			p[i]=i;
		}
	}

	int findSet(int i){
		return (p[i]==i)?i:(p[i]=findSet(p[i]));
	}

	bool isSameSet(int i,int j){
		return findSet(i)==findSet(j);

	}

	void unionSet(int i,int j){
		if(!isSameSet(i,j)){
			int x=findSet(i),y=findSet(j);
			if(rank[x]>rank[y]){
				p[y]=x;
			}else{
				p[x]=y;
				if(rank[x]==rank[y]){
					rank[y]++;
				}
			}
		}
	}
};

int main(){

	int n;
	cin>>n;
	vector<int> x(n,0),y(n,0);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	vector<iii> a(n,iii(ii(0,0),0));
	for(int i=0;i<n;i++){
		a[i] = iii(ii(x[i],y[i]),i);
	}
	sort(a.begin(),a.end());
	vector<iii2> e;
	for(int i=0;i+1<n;i++){
		e.push_back(iii2(a[i+1].first.first-a[i].first.first,ii(a[i+1].second,a[i].second)));
	}
	a.clear();
	for(int i=0;i<n;i++){
		a.push_back(iii(ii(y[i],x[i]),i));
	}
	sort(a.begin(),a.end());
	for(int i=0;i+1<n;i++){
		e.push_back(iii2(a[i+1].first.first-a[i].first.first,ii(a[i+1].second,a[i].second)));
	}
	sort(e.begin(),e.end());

	UnionFind uf(n+10);
	int c = 0;
	for(int i=0;i<(int)e.size();i++){
		int u = e[i].second.first;
		int v = e[i].second.second;
		if(!uf.isSameSet(u,v)){
			uf.unionSet(u,v);
			c+=e[i].first;
		}
	}
	cout<<c<<endl;


	/*int totalcase;
	int testcase=0;
	cin>>totalcase;
	ofstream out;
	out.open("result.txt");

	while(totalcase--){
		testcase++;
		out<<"Case #"<<testcase<<": ";
		cout<<testcase<<": "<<endl;

		//GOGOGO


		//END
	}
	out.close();*/

	return 0;
}
