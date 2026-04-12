#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> P;
const int POINT = 600002;
const int MAX = 200000;
struct Edge{int to;int cost;};
bool vis[POINT];
void Dijk(vector<Edge> G[],int n,int s,long long res[POINT]){
	fill(res,res+n,0);
	fill(vis,vis+n,false);
	priority_queue<P,vector<P>,greater<P>> que;
	P p;
	vis[s]=true;
	res[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		p = que.top();
		que.pop();
		for(Edge e:G[p.second]){
			if(!vis[e.to] || res[e.to]>res[p.second]+e.cost){
				vis[e.to]=true;
				res[e.to]=res[p.second]+e.cost;
				que.push(P(res[e.to],e.to));
			}
		}
	}
}
int main(){
	int N,A[MAX];
	long long ans[POINT];
	vector<Edge> G[POINT];
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<=min(j,N-i-3);k++){
				G[i+j*N].push_back({i+k+2+(j-k)*N,-A[i+k+2]});
			}
		}
	}
	if(N%2)for(int i=0;i<3;i++)G[3*N].push_back({2-i+i*N,-A[2-i]});
	else for(int i=0;i<2;i++)G[3*N].push_back({1-i+i*N,-A[1-i]});
	
	for(int i=0;i<3;i++){
		for(int j=0;j<=i;j++){
			G[N-1-j+i*N].push_back({3*N+1,0});
		}
	}
	
	Dijk(G,3*N+1,3*N,ans);
	
	cout<<-ans[3*N+1];
	return 0;
}