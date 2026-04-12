#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i, m, n) for(int i = m; i < n; i++)
#define reps(i, n) for(int i = 1; i <= n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;

int parent[100010], sz[100010]; // サイズを忘れずに入れる

int root(int a)
{
    if(parent[a]==a)    return a;
    else    return (parent[a]=root(parent[a]));
}

bool same_set(int a, int b)
{
    return (root(a)==root(b));
}

void unite(int a, int b)
{
    if(root(a)!=root(b))
    {
        if(sz[root(a)]<sz[root(b)]) swap(a, b);
        sz[root(a)]+=sz[root(b)];
        parent[root(b)]=root(a);
    }
}

int main()
{
	pai a[100010], b[100010];
	int x, y, n;
	cin >> n;
	rep(i, n)
	{
		cin >> x >> y;
		a[i]=make_pair(x, i+1);
		b[i]=make_pair(y, i+1);
	}
	sort(a, a+n);
	sort(b, b+n);
	pair<int, pair<int, int>> edge[200010];
	rep(i, n-1)
	{
		edge[2*i]=make_pair(a[i+1].first-a[i].first, make_pair(a[i].second, a[i+1].second));
		edge[2*i+1]=make_pair(b[i+1].first-b[i].first, make_pair(b[i].second, b[i+1].second));
	}
	sort(edge, edge+(2*n-2));

	reps(i, n)
    {
        parent[i]=i;
        sz[i]=1;
    }
    ll ans=0;
    int cnt=0;
    rep(i, 2*n-2)
    {
    	pai p=edge[i].second;
    	if(!same_set(p.first, p.second))
    	{
    		unite(p.first, p.second);
    		ans+=edge[i].first;
    		cnt++;
    		if(cnt==n-1) break;
    	}
    }
    cout << ans << endl;
	return 0;
}