#include <bits/stdc++.h>
#define MAX 1000000007
using namespace std;

pair <int,int> p1[100001];
pair <int,int> p2[100001];
vector <pair<int,int> > adj[100001];
bool vis[100001]={false};

long long int prim(int x)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	int y;	long long int minCost=0;	pair<int,int> p;
	
	q.push(make_pair(0,x));
	
	while(!q.empty())
	{
		p=q.top();	q.pop();	x=p.second;
		if(vis[x]) continue;
		minCost+=p.first;	vis[x]=true;
		for(int i=0;i<adj[x].size();i++)
		{
			y=adj[x][i].second;
			
			if(!vis[y]) q.push(adj[x][i]);
		}
	}
	return minCost;
}

int main() 
{
	long long int n,u,v;
	
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
    	cin>>u>>v;
    	
    	p1[i]=make_pair(u,i);
    	p2[i]=make_pair(v,i);
    }
    
    sort(p1,p1+n);
    sort(p2,p2+n);
    
    for(int i=0;i<n-1;i++)
    {
    	adj[p1[i].second].push_back(make_pair(abs(p1[i].first-p1[i+1].first),p1[i+1].second));
    	adj[p1[i+1].second].push_back(make_pair(abs(p1[i].first-p1[i+1].first),p1[i].second));
    	
    	adj[p2[i].second].push_back(make_pair(abs(p2[i].first-p2[i+1].first),p2[i+1].second));
    	adj[p2[i+1].second].push_back(make_pair(abs(p2[i].first-p2[i+1].first),p2[i].second));
    }
    
    cout<<prim(1)<<endl;
	return 0;
}