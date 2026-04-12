

using namespace std;
using ll=long long;
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#define out(S) cout<<(S)<<endl;
#define mod(i) ((i)%(ll)(1000000000 + 7))
ll modpow(ll i, ll j) { ll tmp = 1; while (j) { if (j % 2)tmp = mod(tmp*i); i = mod(i*i); j /= 2; }return tmp; }
#define divmod(a,b) (mod(a * modpow((ll)b,(ll)(1e9+5))))
#define For(i,a,b) for(size_t i=(a);i<(b);i++)
#define rFor(i,a,b) for(size_t i=(a)-1;i>=(b);i--)
#define Rep(i,a) for(size_t i=0;i<(a);i++)
#define rRep(i,a) for(size_t i=(a)-1;i>=0;i--)
#define Foreach(item,collection) for(auto item:collection)

vector<int> makeFactor(int x) {
	vector<int> factors;
	factors.push_back(2);
	for (size_t i = 3; i <= sqrt(x); i+=2)
	{
		bool flag = false;
		Foreach(item, factors) if (i%item == 0) { flag = true; break; }
		if (!flag) factors.push_back(i);
	}
	return factors;
}

vector<int> graph[10];
ll ans = 0;

int dfs(int current, vector<bool> used) {
	if (used[current]) return 0;
	used[current] = true;
	bool all = true;
	Foreach(item, used) if (!item) all = false;
	if (all)return 1;
	Foreach(item, graph[current]) {
		ans += dfs(item, used);
	}
	return 0;
}

int main(){
	int N, M;
	cin >> N >> M;
	Rep(i, M) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	vector<bool> used(N, false);
	dfs(0, used);
	out(ans);
}

