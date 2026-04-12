#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <list>
#include <cstring>
#include <stack>

using namespace std;

#define mod 1000000007

class UnionFind
{
private:
	vector<int> v;

public:
	UnionFind(int n)
	{
		v = vector<int>(n, -1);
	}

	int getparent(int x)
	{
		if(v[x] == -1) return x;
		return v[x] = getparent(v[x]);
	}

	bool add(int x, int y)
	{
		x = getparent(x);
		y = getparent(y);
		if(x == y) return false;
		if(x > y) swap(x, y);
		v[y] = x;
		return true;
	}
};

int main()
{
	int n;
	cin >> n;
	map<int, vector<int> > m[2];
	for(int i = 0; i < n; i++){
		int tmpx, tmpy;
		cin >> tmpx >> tmpy;
		if(m[0].find(tmpx) == m[0].end()) m[0][tmpx] = vector<int>();
		m[0][tmpx].push_back(i);
		if(m[1].find(tmpy) == m[1].end()) m[1][tmpy] = vector<int>();
		m[1][tmpy].push_back(i);
	}
	priority_queue<pair<int, pair<pair<int, int>, int> > > qu;
	for(int j = 0; j < 2; j++){
		for(auto i = m[j].begin(); i != m[j].end(); i++){
			qu.push(make_pair(0, make_pair(make_pair((*i).first, (*i).first), j)));
			auto tmp = i;
			tmp++;
			if(tmp == m[j].end()) break;
			int kyori = (*i).first - (*tmp).first;
			qu.push(make_pair(kyori, make_pair(make_pair((*i).first, (*tmp).first), j)));
		}
	}
	UnionFind uf(n);
	long long int ans = 0;
	while(!qu.empty()){
		int cost = -(qu.top()).first;
		int tmp1 = (((qu.top()).second).first).first;
		int tmp2 = (((qu.top()).second).first).second;
		int isx = ((qu.top()).second).second;
		qu.pop();
		int node1, node2;
		node1 = m[isx][tmp1][0];
		for(int i = 0; i < m[isx][tmp2].size(); i++){
			node2 = m[isx][tmp2][i];
			if(uf.add(node1, node2)) ans += cost;
		}
		node2 = m[isx][tmp2][0];
		for(int i = 0; i < m[isx][tmp1].size(); i++){
			node1 = m[isx][tmp1][i];
			if(uf.add(node1, node2)) ans += cost;
		}
	}
	cout << ans << endl;
	return 0;
}