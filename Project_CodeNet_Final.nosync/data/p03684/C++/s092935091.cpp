//============================================================================
// Name        : hoba.cpp :)
// Author      : (O_O Diab) (Why_not) (el 3AQ)
// Version     :
// Copyright   : please, Don't touch me :(
// Description : problem (I) in C++
// MAIN IDEA   : max sum of S(X) + S(S(X)) => 100 so brute force
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define rw freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
#define pb push_back
#define F first
#define S second
#define pf push_front
#define lp(i,a,b) for (int i=a;i<=(int)b;++i)
#define lp2(i,a,b) for (int i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define EPS 1e-6
// to convert string to number use int a = stoi(string);
// to convert number to string use string s = to_string(int);
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define clr(c,x) memset(c,x,sizeof(c));
using namespace __gnu_pbds;
using namespace std;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = 1e5 + 5, mod = (int) 1e9 + 7, INF = 0x3f3f3f3f;
vii vx, vy;
vector<pair<int, pii>> e;
struct dsu {
	int forests = 0, parent[N], groupsize[N];
	void add(int x) {
		parent[x] = x;
		groupsize[x] = 1;
		forests++;
	}
	int findset(int node) {
		if (parent[node] == node)
			return node;
		return parent[node] = findset(parent[node]);
	}
	bool issameset(int x, int y) {
		return findset(x) == findset(y);
	}
	void link(int i, int j) {
		int x = findset(i), y = findset(j);
		if (x == y)
			return;
		if (groupsize[x] < groupsize[y])
			swap(x, y);
		groupsize[x] += groupsize[y];
		parent[y] = x;
		forests--;
	}
};
int main() {
#ifdef ONLINE_JUDGE
	FAST
#endif
	int n;
	cin >> n;
	lp(i,1,n)
	{
		int x, y;
		cin >> x >> y;
		vx.pb( { x, i });
		vy.pb( { y, i });
	}
	sort(all(vx));
	sort(all(vy));
	lp(i,1,n-1)
	{
		e.pb( { abs(vx[i].F - vx[i - 1].F), { vx[i].S, vx[i - 1].S } });
		e.pb( { abs(vy[i].F - vy[i - 1].F), { vy[i].S, vy[i - 1].S } });
	}
	sort(all(e));
	dsu d;
	lp(i,1,n)
		d.add(i);
	ll cost = 0;
	for (auto u : e) {
		if (d.issameset(u.S.F, u.S.S))
			continue;
		d.link(u.S.F, u.S.S);
		cost += u.F;
	}
	f(cost);
	return 0;
}