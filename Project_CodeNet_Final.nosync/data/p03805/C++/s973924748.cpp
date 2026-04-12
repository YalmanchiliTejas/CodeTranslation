#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#define fin(i,n) for (int i = 0; i < (int)(n); i++)
#define fin2(i,j,m,n) fin(i,m) fin(j,n)
using namespace std;

template <typename T> bool contains(vector<T> list, T value) {
	for (T tmp : list) if (tmp == value) return true;
	return false;
}

int cnt = 0;
int n, m;
map<int, set<int>> linkList;

void dfs(vector<int> path) {

	if (path.size() == n) {
		cnt++;
		return;
	}

	set<int> nextList = linkList[path.back()];
	for (int next : nextList) {
		if (contains(path, next)) continue;

		path.push_back(next);
		dfs(path);
		path.pop_back();
	}
}

int main()
{
	 cin >> n >> m;
	
	fin(i, n) {
		set<int> tmp;
		linkList.insert(make_pair(i + 1, tmp));
	}

	fin(i, m) {
		int a, b; cin >> a >> b;
		linkList.at(a).insert(b);
		linkList.at(b).insert(a);
	}

	vector<int> path;
	path.push_back(1);

	dfs(path);

	cout << cnt << endl;

	return 0;
}