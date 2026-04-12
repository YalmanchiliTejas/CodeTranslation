#include<bits/stdc++.h>
using namespace std;

namespace Union_find {

	class union_find {
		int n;
		std::vector<int> par;
		std::vector<int> rank;
	public:
		union_find(int _n);
		int find(int x);
		void unite(int x, int y);
		bool same(int x, int y) { return find(x) == find(y); }
	};

	union_find::union_find(int _n) :n(_n), par(_n), rank(_n, 1) {
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	};

	int union_find::find(int x) {
		if (par[x] == x)
			return x;
		else
			return par[x] = find(par[x]);
	}

	void union_find::unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (rank[x] < rank[y])
			par[x] = y;
		else
			par[y] = x;

		if (rank[x] == rank[y])
			rank[x]++;

		return;
	}
}

using namespace Union_find;
int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  vector<pair<long long int,int>> xx(n);
  vector<pair<long long int,int>> yy(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    xx[i]={x[i],i};
    yy[i]={y[i],i};
  }
  sort(xx.begin(),xx.end());
  sort(yy.begin(),yy.end());
  set<tuple<long long int,int,int>> edge;
  for(int i=0;i<n-1;i++){
    edge.insert(make_tuple(xx[i+1].first-xx[i].first,xx[i].second,xx[i+1].second));
    edge.insert(make_tuple(yy[i+1].first-yy[i].first,yy[i].second,yy[i+1].second));
  }
  union_find u(n);
  
  long long int res=0;
  for(auto it=edge.begin();it!=edge.end();it++){
    auto val=*it;
    long long int cost=get<0>(val);
    int v1=get<1>(val);
    int v2=get<2>(val);
    if(!u.same(v1,v2)){
      res+=cost;
      u.unite(v1,v2);
    }
  }
  cout<<res<<endl;

  return 0;
}
