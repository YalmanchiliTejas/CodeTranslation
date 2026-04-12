#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include<bitset>

using namespace std;
#define loop(i,n) for(int i = 0; i < (n); ++i)
#define loops(i,f,n) for(int i = (f); i < (n); ++i)
#define INF 9999999
#define lint long long int
#define VEC vector<int>
#define VEC2 vector<vector<int>>
int n;

bool solve(vector<int> dis)
{
	int t = 0;
	bool ret = true;
	loop(i, n)
	{
		if (i > t) { ret = false; break; }
		t = max(i + dis[i] / 10, t);
	}
	return ret;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> dis(n);
	loop(i, n)cin >> dis[i];
	vector<int> dis_back = dis;
	reverse(dis_back.begin(), dis_back.end());
	bool ans = true;
	if (!solve(dis) || !solve(dis_back))ans = false;
	cout << (ans ? "yes" : "no") << endl;
}
