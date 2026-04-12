#include<iostream>
#include<algorithm>
#include <string>
#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define D(n,retu) REP(i,n){cin>>retu[i];}

using namespace std;
typedef long long ll;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
template<typename T>
void fill_all(T& arr, const T& v) {
	arr = v;
}
template<typename T, typename ARR>
void fill_all(ARR& arr, const T& v) {
	for (auto& i : arr) { fill_all(i, v); }
}

//------------------変数-----------------------//
ll n, m;
vector<vector<ll>>graph(19); bool graphb[19];
//-------------------関数----------------------//

ll DFS(ll point, ll count) {
	if (graphb[point]) { return 0; }
	count++;	
	if (count == n) { return 1; }
	graphb[point] = true;
	ll s = graph[point].size();
	ll a = 0;
	REP(i, s) {
		a+=DFS(graph[point][i], count);
	}
	graphb[point] = false;
	return a;
}

int main() {
	cin >> n >> m;
	REP(i, m) {
		ll a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cout << DFS(1, 0) << endl;;
}