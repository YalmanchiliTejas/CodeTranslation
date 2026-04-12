#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class UnionFind {
public:
	explicit UnionFind(int N) : root(N, -1) {}
	int getRoot(int v){ return root[v] == -1 ? v : root[v] = getRoot(root[v]); }
	void merge(int a, int b){
		int p = getRoot(a), q = getRoot(b);
		if(p != q) root[q] = p;
	}
private:
	vector<int> root;
};

int main(){
	int N;
	while(cin >> N){
		map<int,int> mapX, mapY;
		vector<int> dictX, dictY;
		UnionFind uf(N);		
		for(int i=0;i<N;i++){
			int x, y; cin >> x >> y;
			if(mapX.count(x)){
				uf.merge(mapX[x], i);
			} else {
				mapX[x] = i;
			}
			if(mapY.count(y)){
				uf.merge(mapY[y], i);
			} else {
				mapY[y] = i;
			}
			dictX.push_back(x);
			dictY.push_back(y);
		}
		auto toUnique = [](vector<int>& v){
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
		};
		toUnique(dictX);
		toUnique(dictY);
		vector<pair<int, pair<int,int>>> vp;
		auto pushCosts = [&](const vector<int>& dict, map<int,int>& mp){
			for(int i=0;i+1<dict.size();i++){
				vp.push_back(make_pair(dict[i+1] - dict[i], make_pair(mp[dict[i]], mp[dict[i+1]])));				
			}
		};
		pushCosts(dictX, mapX);
		pushCosts(dictY, mapY);
		sort(vp.begin(), vp.end());
		UnionFind whole(N);
		long long res = 0;
		for(auto& p : vp){
			int a = uf.getRoot(p.second.first);
			int b = uf.getRoot(p.second.second);
			if(whole.getRoot(a) != whole.getRoot(b)){
				res += p.first;
				whole.merge(a, b);
			}
		}
		cout << res << endl;
	}
}
