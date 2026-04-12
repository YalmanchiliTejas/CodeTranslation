#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define FORR(i,a,b)for(ll i=(a);i<=(b);i++)
#define repR(i,n) for(ll i=n;i>=0;i--)
#define P pair<ll, ll>
#define sz(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<ll>
#define COUT(x) cout<<(x)<<endl
#define MA map<ll,ll>
#define SE set<ll>
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,VE,greater<ll>>
#define COUT(x) cout<<(x)<<endl
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define EPS (1e-10)
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
bool prime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}


const long long MOD = 1000000007;
const long long INF = 1e16;
#define int long long

const int MAX_N = 10;
const int MAX_V = 110;

bool graph[MAX_N][MAX_N];

int dfs(int v, int N, bool visited[MAX_N]) {
	bool all_visited = true;
	rep(i, N) {
		if (!visited[i]) all_visited = false;
	}
	if (all_visited)return 1;
	int ret = 0;
	rep(i, N) {
		if (!graph[v][i])continue;
		if (visited[i])continue;
		visited[i] = true;
		ret += dfs(i, N, visited);
		visited[i] = false;
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	int N, M;
	cin >> N >> M;
	rep(i, M) {
		int A, B; cin >> A >> B;
		graph[A - 1][B - 1] = graph[B - 1][A - 1] = true;
	}
	bool visited[MAX_N];
	rep(i, N)visited[i] = false;
	visited[0] = true;
	cout << dfs(0, N, visited) << endl;
	return 0;
}
