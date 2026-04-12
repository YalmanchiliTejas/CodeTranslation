#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;
int ans1 = 0 , ans2 = 0;
const int MAX = 100005;
vector<pair<int , pair<int , int> > > v;

int p[MAX];
int sz[MAX];
int n;
void addEdges(vector<pair<pair<int , int> , int> > &t)
{
	for(int i = 1; i < n; i++)
	{
		v.PB({min(abs(t[i].X.X - t[i - 1].X.X) , abs(t[i].X.Y - t[i - 1].X.Y)) , {t[i].Y , t[i - 1].Y} });
	}
}
int find(int u)
{
	if(p[u] == u)
		return u;
	return p[u] = find(p[u]);
}
void unite(int u , int v)
{
	if(find(u) == find(v))
		return;
	u = find(u);
	v = find(v);
	if(sz[u] > sz[v])
	{
		swap(u , v);
	}
	sz[v] += sz[u];
	p[u] = v;
}
		
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		p[i] = i;
		sz[i] = 1;
	}
	vector<pair<pair<int , int> , int> > t(n);
	for(int i = 0; i < n; i++)
	{
		cin >> t[i].X.X >> t[i].X.Y;
		t[i].Y = i;
	}
	sort(t.begin() , t.end());
	addEdges(t);
	reverse(t.begin() , t.end());
	addEdges(t);
	
	for(auto &x : t)
	{
		swap(x.X.X , x.X.Y);
	}
	sort(t.begin() , t.end());
	addEdges(t);
	reverse(t.begin() , t.end());
	addEdges(t);
	
	sort(ALL(v));
	int ans = 0;
	for(auto x : v)
	{
		if(find(x.Y.X) != find(x.Y.Y))
		{
			ans += x.X;
			unite(x.Y.X , x.Y.Y);
		}
	}
	cout << ans;
}
