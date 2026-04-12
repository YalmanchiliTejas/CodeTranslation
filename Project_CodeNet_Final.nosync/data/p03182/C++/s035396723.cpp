#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
#define lc (root<<1)
#define rc (root<<1|1)
#define lowbit(x) (x&-x)
using namespace std;
const int N = 2e5+7;
const ll inf = 1e18;
int n, m;
ll tre[N<<2], tag[N<<2];
vector<pair<int, int> > vec[N];
void push_down(int root)
{
	if(tag[root])
	{
		ll c = tag[root];
		tag[lc] += c;
		tag[rc] += c;
		tre[lc] += c;
		tre[rc] += c;
		tag[root] = 0;
	}
	return;
}
ll query(int root, int l, int r, int fl, int fr)
{
	if(l>fr||r<fl)
	{
		return 0;
	}
	if(l>=fl&&r<=fr)
	{
		return tre[root];
	}
	push_down(root);
	return max(query(lc, l, mid, fl, fr), query(rc, mid+1, r, fl, fr));
}
void modify(int root, int l, int r, int fl, int fr, ll v)
{
	if(l>fr||r<fl)
	{
		return;
	}
	if(l>=fl&&r<=fr)
	{
		tre[root] += v;
		tag[root] += v;
		return;
	}
	push_down(root);
	modify(lc, l, mid, fl, fr, v);
	modify(rc, mid+1, r, fl, fr, v);
	tre[root] = max(tre[lc], tre[rc]);
	return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
    {
    	int l, r, v;
    	scanf("%d%d%d", &l, &r, &v);
    	vec[r].push_back(make_pair(l, v));
    }
    for(int i = 1; i <= n; i++)
    {
    	sort(vec[i].begin(), vec[i].end(), greater<pair<int, int> >());
    }
    for(int i = 1; i <= n; i++)
    {
		ll res;
		res = query(1, 1, n, 1, i);
    	for(int j = 0; j < vec[i].size(); j++)
    	{
			modify(1, 1, n, vec[i][j].first, i, vec[i][j].second);
    	}
    	modify(1, 1, n, i, i, res);
    }
    printf("%lld\n", max(0ll, query(1, 1, n, 1, n)));
    return 0;
}