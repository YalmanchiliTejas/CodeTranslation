#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 4010
typedef pair<int,int> P;
typedef pair<int,pair<int,int> >PP;

ll primsum=0;
vector<P> v[N],u[N];
priority_queue<PP,vector<PP>,greater<PP> >Q;
void Qpush(int cost,int now,int from){
    Q.push(make_pair(cost,make_pair(now,from)));
}
void Prim(){
    bool vis[N]={0};
    Qpush(0,0,-1);
    while(!Q.empty()){
	int cost=Q.top().first;
	int x=Q.top().second.first;
	int from=Q.top().second.second;
	Q.pop();
	if(vis[x]==true)continue;
	vis[x]=true;
	if(from!=-1){
	    u[x].push_back(make_pair(cost,from));
	    u[from].push_back(make_pair(cost,x));
	    primsum+=cost;
	}
	lol(i,v[x].size()){
	    if(v[x][i].second==from)continue;
	    Qpush(v[x][i].first,v[x][i].second,x);
	}
    }
}

ll ans[N][N];
void DFS(int x,int maxi,int root,int from){
    ans[root][x]=maxi;
    lol(i,u[x].size()){
	if(u[x][i].second==from)continue;
	int cost=u[x][i].first;
	DFS(u[x][i].second,max(maxi,cost),root,x);
    }
}

int main(){
    int n,m,q;cin>>n>>m;
    lol(i,m){
	int a,b,c;cin>>a>>b>>c;a--,b--;
	v[a].push_back(make_pair(c,b));
	v[b].push_back(make_pair(c,a));
    }
    Prim();
    lol(i,n)DFS(i,0,i,-1);
    cin>>q;
    lol(i,q){
	int a,b;cin>>a>>b;a--,b--;
	cout<<primsum-ans[a][b]<<endl;
    }
    return 0;
}
