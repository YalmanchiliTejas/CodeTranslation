#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<iomanip>
#include<set>
#include<stdio.h>
#include<string.h>

#define ll long long 
#define ull unsigned long long
#define ld long double
#define all(vec) (vec).begin(),(vec).end()
#define allr(vec) (vec).rbegin(),(vec).rend()
#define viewVec(vec) for(auto i:(vec))cout << i << " ";cout << endl
using namespace std;

ll  a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
ll ans = 0, sum = 0, mn = 1e18, mx = 0, cnt = 0;
const ll M = 1000000007;

map<char, int>mp;
vector<int>vec;
vector<int>vec2;
vector<int>res;


ll gcd(ll a, ll b) { if (b == 0)return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a*b) / gcd(a, b); }


/*(constructive)*/

vector<int>adj[10];
void dfs(vector<int>visited, int node,int height)
{
	visited[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		if (!visited[adj[node][i]])
		{
			dfs(visited, adj[node][i], height + 1);
		}
	}
	if (height == n)ans++;
}

int main()
{
	vector<int>visited(10,0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(visited, 1,1);
	cout << ans << endl;
	return 0;
}