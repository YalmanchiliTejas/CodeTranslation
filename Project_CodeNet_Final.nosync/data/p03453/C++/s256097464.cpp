#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#define INF 10000000000000000LL
#define MOD 1000000007LL
using namespace std;
typedef pair <long long int, int> P;
struct edge {
	int to;
	long long int cost;
};

int main()
{
	int n, m, s, t, u, v;
	long long int d;
	vector<edge> G[100000];
	long long int dmins[100000], dmint[100000], num1[100000], num2[100000];
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	s--;
	t--;
	for(int i=0; i<m; i++){
		scanf("%d %d %lld", &u, &v, &d);
		u--;
		v--;
		edge g;
		g.cost=d, g.to=v;
		G[u].push_back(g);
		g.to=u;
		G[v].push_back(g);
	}

	priority_queue<P, vector<P>, greater<P> > que;
	fill(dmins, dmins+n, INF);
	dmins[s]=0;
	que.push(P(0, s));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v1=p.second;
		if(dmins[v1]<p.first) continue;
		for(int i=0; i<G[v1].size(); i++){
			edge e=G[v1][i];
			if(dmins[e.to]>dmins[v1]+e.cost){
				dmins[e.to]=dmins[v1]+e.cost;
				que.push(P(dmins[e.to], e.to));
			}
		}
	}
	fill(dmint, dmint+n, INF);
	dmint[t]=0;
	que.push(P(0, t));
	while(!que.empty()){
		P p=que.top();
		que.pop();
		int v1=p.second;
		if(dmint[v1]<p.first) continue;
		for(int i=0; i<G[v1].size(); i++){
			edge e=G[v1][i];
			if(dmint[e.to]>dmint[v1]+e.cost){
				dmint[e.to]=dmint[v1]+e.cost;
				que.push(P(dmint[e.to], e.to));
			}
		}
	}
	long long int x=dmins[t];

	fill(num1, num1+n, 0);
	num1[s]=1;
	for(int i=0; i<n; i++){
      que.push(P(dmins[i], i));
    }
	while(!que.empty()){
		P p=que.top();
		que.pop();
        int v1=p.second;
		for(int i=0; i<G[v1].size(); i++){
			edge e=G[v1][i];
			if(dmins[v1]==dmins[e.to]+e.cost){
				num1[v1]=(num1[e.to]+num1[v1])%MOD;
			}
		}
	}
	fill(num2, num2+n, 0);
	num2[t]=1;
	for(int i=0; i<n; i++){
      que.push(P(dmint[i], i));
    }
	while(!que.empty()){
		P p=que.top();
		que.pop();
        int v1=p.second;
		for(int i=0; i<G[v1].size(); i++){
			edge e=G[v1][i];
			if(dmint[v1]==dmint[e.to]+e.cost){
				num2[v1]=(num2[e.to]+num2[v1])%MOD;
			}
		}
	}
	long long int ans=0;
	for(int k=0; k<n; k++){
		if(2*dmins[k]<x){
			for(int i=0; i<G[k].size(); i++){
				edge e=G[k][i];
				if(2*dmint[e.to]<x && dmint[e.to]+dmins[k]+e.cost==x){
					ans=(ans+num1[k]*num1[k]%MOD*num2[e.to]%MOD*num2[e.to]%MOD)%MOD;
				}
			}
		}else if(2*dmins[k]==x && 2*dmint[k]==x){
			ans=(ans+num1[k]*num1[k]%MOD*num2[k]%MOD*num2[k]%MOD)%MOD;
		}
	}
	ans=(num1[t]*num1[t]%MOD+MOD-ans)%MOD;
	printf("%lld\n", ans);

	return 0;
}