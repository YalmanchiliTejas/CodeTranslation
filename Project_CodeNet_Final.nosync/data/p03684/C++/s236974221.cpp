#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};


void solve(long long N, vector<long long> x, vector<long long> y){
    vector< pair<ll,int> > X,Y;
    for(int i = 0 ; i < x.size() ; i++){
        X.push_back({x[i],i});
    }
    for(int i = 0 ; i < y.size() ; i++){
        Y.push_back({y[i],i});
    }
    UnionFind uf(N);
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());

    vector<pair<ll,pair<int,int>>> es;
    auto func = [&](vector< pair<ll,int> > X ){
        for(int i = 0 ; i + 1 < X.size() ; i++){
            int id1 = X[i].second;
            int id2 = X[i+1].second;
            es.push_back({min(abs(x[id1]-x[id2]),abs(y[id1]-y[id2])),{id1,id2}});
        }
    };
    func(X);
    func(Y);
    sort(es.begin(),es.end());
    ll ans = 0;
    for( auto e : es ){
        if( uf.unionSet(e.second.first,e.second.second)){
            ans += e.first;
        }
    }
    cout << ans << endl;

}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> y(N-1+1);
	vector<long long> x(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&x[i]);
		scanf("%lld",&y[i]);
	}
	solve(N, x, y);
	return 0;
}

