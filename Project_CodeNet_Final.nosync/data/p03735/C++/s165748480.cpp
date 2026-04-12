#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#define maxn 200009
using namespace std;
int n;
vector<pair<int,int> >G;
int rk[maxn];
multiset<int>X, Y;

bool cmp(int x, int y){
	return G[x].second > G[y].second;
}

long long getans(){
	auto it = X.begin();
	long long x1 = *it;
	it = X.end();
	--it;
	long long x2 = *it;
	it = Y.begin();
	long long y1 = *it;
 	it = Y.end();
 	--it;
 	long long y2 = *it;
 	return (x2 - x1) * (y2 - y1);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		G.push_back(make_pair(min(x, y), max(x, y)));
	}
	
	sort(G.begin(), G.end());
	for(int i =0 ;i < n; i++)
		rk[i] = i;
	
	sort(rk, rk + n, cmp);
	
	for(int i = 0; i < n; i++){
		X.insert(G[i].first);
		Y.insert(G[i].second);
	}
	
	long long ans = getans();

	
	for(int i = 0; i < n; i++){
		if(rk[i] == 0)
			continue;
		auto it = Y.find(G[rk[i]].second);
		Y.erase(it);
		it = X.find(G[rk[i]].first);
		X.erase(it);
		Y.insert(G[rk[i]].first);
		X.insert(G[rk[i]].second);
		ans = min(ans, getans());
	}
	cout << ans << endl;
	return 0;
	
}