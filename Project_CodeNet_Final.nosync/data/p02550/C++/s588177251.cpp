#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
//#include"testlib.h"
#define endl "\n"
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define sz(s)    (int)(s.size())
#define PI acos(-1)
#define EPS 1e-8
#define watch(x) cout << (#x)<<" = "<<x<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("street.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}
const int N = 2e5 + 10;
int depth[N];
ll n, x, m;
ll getNextNode(int node) {
	return (1LL * node * node) % m;
}
ll forward(ll node, ll k) {
	if (k == 0)
		return node;
	return node + forward(getNextNode(node), k - 1);
}
ll go(ll node, ll k, int dis = 1) {
	if (k == 0)
		return node;
	if (depth[node]) {
		int cycle = dis - depth[node];
		depth[node] = 0;
		return forward(node, k % cycle) + forward(node, cycle - 1LL) * (k / cycle);
	}
	depth[node] = dis;
	return node + go(getNextNode(node), k - 1, dis + 1);
}
int main() {
	file();
	fast();
	cin >> n >> x >> m;
	cout << go(x, n - 1) << endl;
	return 0;
}