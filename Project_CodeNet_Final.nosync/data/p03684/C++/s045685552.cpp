#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>  
#include<cstdio>  
#include<fstream>  
#include<iomanip>
#include<algorithm>  
#include<cmath>  
#include<deque>  
#include<vector>  
#include<assert.h>
#include<bitset>
#include<queue>  
#include<string>  
#include<cstring>  
#include<map>  
#include<stack>  
#include<set>
#include<functional>
#define pii pair<int, int>
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define eps 0.00000001
#define mst(a,i) memset(a,i,sizeof(a))
#define all(n) n.begin(),n.end()
#define lson(x) ((x<<1))  
#define rson(x) ((x<<1)|1) 
#define inf 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
const int maxn = 1e5 + 5;
class node {
public:
	int u, v, w;
	node(int a, int b, int c) :u(a), v(b), w(c) {};
};
int fa[maxn];
int getf(int i) { return i == fa[i] ? i : fa[i] = getf(fa[i]); }
vector<node>edge;
bool cmp(const node&a, const node&b)
{
	return a.w < b.w;
}
class T {
public:
	int value, id;
	T(int ta, int tb) :id(ta), value(tb) {};
	bool operator<(const T &a)
	{
		return value < a.value;
	}
	T(){};
};
T sx[maxn], sy[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int i, j, k, m, n, ta, tb;
	cin >> n;
	for (int i = 1; i <= n; ++i)fa[i] = i;
	for (int i = 1; i <= n; ++i)
	{
		cin >> sx[i].value >> sy[i].value;
		sx[i].id = sy[i].id = i;
	}
 
	sort(sx + 1, sx + n + 1);
	sort(sy + 1, sy + 1 + n);
	edge.push_back(node(sx[1].id, sx[2].id, abs(sx[1].value - sx[2].value)));
	edge.push_back(node(sx[n].id, sx[n - 1].id, abs(sx[n].value - sx[n - 1].value)));
	edge.push_back(node(sy[1].id, sy[2].id, abs(sy[1].value - sy[2].value)));
	edge.push_back(node(sy[n].id, sy[n - 1].id, abs(sy[n].value - sy[n - 1].value)));
	for (int i = 2; i < n; ++i)
	{
		edge.push_back(node(sx[i].id, sx[i - 1].id, abs(sx[i].value - sx[i - 1].value)));
		edge.push_back(node(sx[i].id, sx[i + 1].id, abs(sx[i].value - sx[i + 1].value)));
		edge.push_back(node(sy[i].id, sy[i + 1].id, abs(sy[i].value - sy[i + 1].value)));
		edge.push_back(node(sy[i].id, sy[i - 1].id, abs(sy[i].value - sy[i - 1].value)));
	}
	sort(edge.begin(), edge.end(), cmp);
	ll ans = 0;
	for (i = 0; i <edge.size(); ++i)
	{
		if (getf(edge[i].u) != getf(edge[i].v))
		{
			ans += edge[i].w;
			fa[getf(edge[i].u)] = getf(edge[i].v);
		}
	}
	cout << ans << endl;
	return 0;
}