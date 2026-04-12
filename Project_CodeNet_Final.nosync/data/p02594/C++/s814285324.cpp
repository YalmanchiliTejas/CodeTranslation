#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define    boost        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    nl           "\n"
#define    ll           long long
#define    pb           push_back
#define    mpr          make_pair
#define    fr(i,a,n)    for(ll i=a;i<n;++i)
#define    fr0(i,n)     for(ll i=0;i<n;++i)
#define    pii          pair<int, int>
#define    FO           find_by_order
#define    OK           order_of_key
#define    mem(a)       memset(a,0,sizeof(a))
#define    ff           first
#define    ss           second


typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
set_t;


void fio()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
	double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "\nExecuted in: " << fixed
	     << time_taken << setprecision(9);
	cout << " sec";
#endif
}

///----------------------------- | FUNCTIONS | --------------------------------------///

/*
const int N = 2e5 + 5;

vector<int> adj[N];
bool visited[N];
//int val[N];
//int depth[N];
//int parent[N];

void dfs(int v)
{
	visited[v] = true;
	for (int u : adj[v])
	{
		if (!visited[u])
		{
			//parent[u] = v;
			//depth[u] = depth[v] + 1;
			dfs(u);
		}
	}
}
*/

// left shift << multiply by 2
// right shift >> divide by 2

///----------------------------- | START FROM HERE | --------------------------------------///

//#define int long long //change int main to int32_t main


void solve()
{
	int x; cin >> x;
	if (x >= 30) cout << "Yes\n";
	else cout << "No\n";

}





int main()
{
	auto start = chrono::high_resolution_clock::now();
	boost;
	fio();
	int t;
	t = 1;
	//cin >> t;
	while (t--) solve();
	auto end = chrono::high_resolution_clock::now();
	TIME(start, end);
	return 0;
}


