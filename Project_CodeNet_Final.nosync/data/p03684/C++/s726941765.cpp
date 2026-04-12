#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
typedef long long LL;
const int MAXN = 1e5+17;
const LL MOD = 1e9+7;
vector<pair<LL,LL> > G[MAXN];
map<pair<LL,LL >,LL > mp;
LL mincost[MAXN];		// 从集合X出发的边到每个顶点的最小权值
bool used[MAXN];		// 顶点i是否包含在集合X中
int V,m=0;					// 顶点数
// first 最短路径，second顶点编号
typedef pair<LL, LL> P;

LL prim()
{
	V = m;
	LL res = 0;
	for (int i = 0; i < V; ++i)
	{
		mincost[i] = 9999999999999;
	}
	memset(used, 0, V * sizeof(bool));
	mincost[0] = 0;
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, 0));  
	while (!que.empty())
	{
		P p = que.top(); que.pop();
		LL v = p.second;  
		if (used[v] || p.first > mincost[v]) continue;
		used[v] = true;
		res += 1LL*mincost[v];
		for (int i = 0; i < G[v].size(); ++i)
		{
			LL to = G[v][i].first,cost = G[v][i].second;
			if (mincost[to] > cost)
			{
				mincost[to] = cost;
				que.push(P(mincost[to], to));
			}
		}
	}
	assert(res<(1LL<<32));
	return res;
}
int main(int argc ,char const *argv[])
{
    #ifdef noob
    freopen("Input.txt","r",stdin);freopen("Output.txt","w",stdout);
    #endif	
    int n;
    cin>>n;
    vector<pair<LL,LL > > x,y,all;
    for (int i = 0; i < n; ++i)
    {
    	LL a,b;
    	cin>>a>>b;
    	// if(mp[{a,b}]!=1)
    	// {
    		//mp[{a,b}]=1;
    		m++;
    		all.push_back({a,b});
    		x.push_back({a,i});
    		y.push_back({b,i});
    	//}
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < m; ++i)
    {
    	LL tx = all[i].first,ty = all[i].second;
    	pair<LL,LL > tp =  {tx,i};
    	vector<pair<LL,LL > > :: iterator itx1 = lower_bound(x.begin(), x.end(),tp);
    	if((itx1+1)!=x.end()&&(*(itx1+1)).first==tx) 
    	{
    		itx1++;
    	}
    	else if(itx1!=x.begin()) itx1--;
		LL cost = (tx-((*itx1).first)),v = ((*itx1).second);
    	G[i].push_back({v,cost});
    	G[v].push_back({i,cost});
    	itx1 = upper_bound(x.begin(), x.end(), tp);
    	if(itx1!=x.end())
    	{
    		cost = ((*itx1).first)-tx,v = ((*itx1).second);
    		G[i].push_back({v,cost});
    		G[v].push_back({i,cost});
    	}

    	tp =  {ty,i};
    	itx1 = lower_bound(y.begin(), y.end(), tp);
    	if((itx1+1)!=y.end()&&(((*(itx1+1)).first==ty))) 
    	{
    		itx1++;
    	}
    	else if(itx1!=y.begin()) itx1--;
		cost = ty-((*itx1).first),v = ((*itx1).second);
    	G[i].push_back({v,cost});
    	G[v].push_back({i,cost});
    	itx1 = upper_bound(y.begin(), y.end(), tp);
    	if(itx1!=y.end())
    	{
    		cost = ((*itx1).first)-ty,v = ((*itx1).second);
    		G[i].push_back({v,cost});
    		G[v].push_back({i,cost});
    	}
    }
    cout<<1LL*prim()<<endl;
    return 0;
}
