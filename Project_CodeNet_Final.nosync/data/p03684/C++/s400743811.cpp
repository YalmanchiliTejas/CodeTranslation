#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;

struct UnionFind{
    public:
    vector<int> data;
    UnionFind(int sz){
        data.assign(sz, -1);
    }
    int find(int p){
        if(data[p]<0) return p;
        return data[p]=find(data[p]);
    }
    bool unite(int X, int Y){
        X=find(X), Y=find(Y);
        if(X==Y) return false;
        if(data[X]>data[Y]) swap(X, Y);
        data[X] += data[Y];
        data[Y]=X;
        return true;
    }
    int size(int k){
        return -data[find(k)];
    }
};

int main() {
	int N;
	cin >> N;
	vector<pair<ll, int>> vx(N), vy(N);
	for(int i=0; i<N; ++i){
	    ll x, y;
	    cin >> x >> y;
	    vx[i]=make_pair(x, i);
	    vy[i]=make_pair(y, i);
	}
	vector<pair<ll, pair<int, int>>> ed;
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	for(int i=0; i+1<N; ++i){
	    ed.push_back(make_pair(vx[i+1].first-vx[i].first, make_pair(vx[i].second, vx[i+1].second)));
	    ed.push_back(make_pair(vy[i+1].first-vy[i].first, make_pair(vy[i].second, vy[i+1].second)));
	}
	sort(ed.begin(), ed.end());
	UnionFind uf(N);
	int cnt=1, now=0;
	ll ans=0;
	while(cnt<N){
	    if(uf.unite(ed[now].second.first, ed[now].second.second)){
	        ans += ed[now].first;
	        ++cnt;
	    }
	    ++now;
	}
	cout << ans << endl;
	return 0;
}
