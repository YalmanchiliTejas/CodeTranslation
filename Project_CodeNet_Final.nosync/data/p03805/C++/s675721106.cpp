#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/stdc++.h>

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define mod 1000000007
#define pii pair <int, int>
#define all(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = x; i <= y; i++)
//#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

//using namespace __gnu_pbds;

using namespace std;

//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, a, b, m, ans;

bool vis[10];

vector <int> E[10];

void dfs(int node, int now)
{
	if (now == n){
		ans++;
		return;
	}
	
	vis[node] = 1;
	for (auto i: E[node])
		if (!vis[i]) dfs(i, now+1);
	vis[node] = 0;
}

int main()
{
	cin >> n >> m;
	
	FOR (i, 1, m) {
		cin >> a >> b;
		
		E[a].pb(b);
		E[b].pb(a);
	}
	
	dfs(1, 1);
	
	cout << ans;
}
