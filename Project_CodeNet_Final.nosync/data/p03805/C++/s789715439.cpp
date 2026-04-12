#include <cstdio>
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(int i = 0; i < n; i++)
#define RREP(i, n) for(int i = n - 1; i >= 0; i--)
#define REP2(i, n, k) for(int i = 0; i < n; i += k)

int n, m;
vector<int> v[8];

int dfs(int k, bool f[]){
	int sum = 0;

	int i;
	for(i = 0; i < n; i++){
		if(!f[i])break;
	}
	if(i == n)return 1;

	for(auto x : v[k]){
		if(!f[x]){
			f[x] = true;
			sum += dfs(x, f);
			f[x] = false;
		}
	}

	return sum;
}

int main()
{
    cin >> n >> m;
	REP(i, m){
		int a, b;
		cin >> a >> b;
		a--;b--;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	bool f[8] = {};
	f[0] = true;

	cout << dfs(0, f) << endl;
}