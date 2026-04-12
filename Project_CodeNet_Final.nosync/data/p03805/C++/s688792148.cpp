#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <utility> 

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;





int main(){
	vector< pair<int, int> > edge;
	
	int n, m;
	cin >> n >> m;

	
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		auto p1 = make_pair(a, b);
		auto p2 = make_pair(b, a);
		edge.push_back(p1);
		edge.push_back(p2);

	}

	vector<int> node;
	rep(i, 1, n + 1) {
		node.push_back(i);
	}


	int ans = 0;
	do {
		int match = 0;
		rep(i, 0, n - 1) {
			int from = node[i];
			int to = node[i + 1];
			for (auto x : edge) {
				if (from == x.first && to == x.second) {
					match++;
				}
			}
		}
		if (match == n - 1 && node[0]==1)ans++;
	} while (next_permutation(node.begin(), node.end()));

	cout << ans << endl;
	




	return 0;
}