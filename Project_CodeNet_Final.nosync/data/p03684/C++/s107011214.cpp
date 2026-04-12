#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define INF 10000000000000000LL

using namespace std;
typedef pair <long long int, int> P;
struct edge {
	int to;
	long long int cost;
};

int main()
{
	int n;
	long long int x, y;
	vector<edge> G[100000];
	multimap<long long int, int> xi, yi;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%lld %lld", &x, &y);
		xi.insert(make_pair(x, i));
		yi.insert(make_pair(y, i));
	}
	for(auto itr=xi.begin(); itr!=xi.end(); itr++){
		auto itr1=itr;
		itr1++;
		if(itr1!=xi.end()){
			edge e;
			e.to=itr->second;
			e.cost=itr1->first-itr->first;
			G[itr1->second].push_back(e);
			e.to=itr1->second;
			G[itr->second].push_back(e);
		}
	}
	for(auto itr=yi.begin(); itr!=yi.end(); itr++){
		auto itr1=itr;
		itr1++;
		if(itr1!=yi.end()){
			edge e;
			e.to=itr->second;
			e.cost=itr1->first-itr->first;
			G[itr1->second].push_back(e);
			e.to=itr1->second;
			G[itr->second].push_back(e);
		}
	}
	priority_queue<P, vector<P>, greater<P> > que;
	long long int ans=0;
	for(int i=0; i<G[0].size(); i++){
		edge e=G[0][i];
		que.push(P(e.cost, e.to));
	}
	set<int> used;
	used.insert(0);
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v=p.second;
		if(used.find(v)!=used.end()) continue;
		ans=ans+p.first;
		used.insert(v);
		for(int i=0; i<G[v].size(); i++){
			edge e=G[v][i];
			if(used.find(e.to)==used.end()){
				que.push(P(e.cost, e.to));
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}