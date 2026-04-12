#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(int i = m;i >= n;--i)
#define INF INT_MAX/2
using namespace std;
using ll = long long;
using R = double;
using Data = pair<ll, vector<int>>;
const ll MOD = 1e9 + 7;
const ll inf = 1LL << 50;
struct edge { ll from; ll to; ll cost; };

vector<int>e[10];
int used[10];
int n, m;

int dfs(int now,int sum) {
	if (sum == n)return 1;
	int ret = 0;
	fore(x,e[now]) {
		if (used[x] == 0) {
			used[x] = 1;
			ret += dfs(x,sum+1);
			used[x] = 0;
		}
	}
	return ret;
}


int main() {
	cin >> n >> m;

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a].pb(b);
		e[b].pb(a);
	}

	used[0] = 1;
	cout << dfs(0, 1) << endl;

	return 0;
}