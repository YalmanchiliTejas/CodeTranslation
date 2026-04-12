#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;
#define INF 999999999

int main(){
	int N;
	cin>>N;
	vector<P> x_arr;
	vector<P> y_arr;
	
	for (int i=0;i<N;i++){
		int buf;
		cin>>buf;
		x_arr.push_back(P(buf,i));
		cin>>buf;
		y_arr.push_back(P(buf,i));
	}

	sort(x_arr.begin(), x_arr.end());
	sort(y_arr.begin(), y_arr.end());

	vector< vector<P> > edge(N);
	for(int i=0;i<N-1;i++){
		int from=x_arr[i].second;
		int to=x_arr[i+1].second;
		int cost=x_arr[i+1].first-x_arr[i].first;
		edge[from].push_back(P(cost, to));
		edge[to].push_back(P(cost,from));
		
		from=y_arr[i].second;
		to=y_arr[i+1].second;
		cost=y_arr[i+1].first-y_arr[i].first;
		edge[from].push_back(P(cost, to));
		edge[to].push_back(P(cost,from));
	}


	int minCost[N];
	fill(minCost,minCost+N,INF);
	minCost[0]=0;
	priority_queue<P> pq;
	pq.push(P(-0,0));

	int totalCost=0;

	while(!pq.empty()){
		P p=pq.top();pq.pop();
		int u=p.second;
		if (minCost[u]<-p.first) continue;
		totalCost-=p.first;
		minCost[u]=-INF;
		
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].second;
			int c=edge[u][i].first;
			
			if (c<minCost[v]){
				minCost[v]=c;
				pq.push(P(-c,v));
			}
		}
	}

	cout<<totalCost<<endl;

	return 0;
}
