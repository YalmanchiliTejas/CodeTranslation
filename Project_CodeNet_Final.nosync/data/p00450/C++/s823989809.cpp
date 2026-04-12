#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define INF_LL 9000000000000000000
#define INF 2000000000

#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, PII> PPII;
typedef pair<int, PPII> PPPII;

class Union_find{
private:
	vector<int> par;
	vector<int> rank;
	int n;

public:
	Union_find(int a){
		n = a;
		for(int i = 0;i < n;i++){
			par.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y){
		return find(x) == find(y);
	}
};

int main(void){
	int n;
	while(cin >> n && n){
		stack<PII> stone;
		int a;
		cin >> a;
		if(a) stone.push({1, 1});
		else stone.push({1, 0});
		REP(i, n-1){
			cin >> a;
			if(i%2 == 0 && a != stone.top().second){
				PII b = stone.top();
				stone.pop();
				if(stone.size()) stone.top().first += b.first+1;
				else stone.push({b.first+1, a});
			}else if(a != stone.top().second){
				stone.push({1, a});
			}else{
				stone.top().first++;
			}

		}
		int res = 0;
		while(stone.size()){
			PII b = stone.top();
			stone.pop();
			if(b.second == 0) res += b.first;
		}
		cout << res << endl;
	}
}