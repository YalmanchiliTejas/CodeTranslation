#include <iostream>
#include <vector>
#include <algorithm>

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
		vector<pair<int, int>> dictX, dictY;
		UnionFind uf(N);
		for(int i=0;i<N;i++){
			int x, y; cin >> x >> y;
			dictX.emplace_back(x, i);
			dictY.emplace_back(y, i);
		}
		sort(dictX.begin(), dictX.end());
		sort(dictY.begin(), dictY.end());
		vector<pair<int, pair<int,int>>> vp;
		auto pushCosts = [&](const vector<pair<int, int>>& dict){
			for(int i=0;i+1<dict.size();i++){
				auto& a = dict[i];
				auto& b = dict[i+1];
				vp.push_back(make_pair(b.first - a.first, make_pair(a.second, b.second)));				
			}
		};
		pushCosts(dictX);
		pushCosts(dictY);
		sort(vp.begin(), vp.end());
		long long res = 0;
		for(auto& p : vp){
			int a = uf.getRoot(p.second.first);
			int b = uf.getRoot(p.second.second);
			if(a != b){
				res += p.first;
				uf.merge(a, b);
			}
		}
		cout << res << endl;
	}
}
