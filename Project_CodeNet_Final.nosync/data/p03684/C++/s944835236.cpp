#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#define MAX_N 100000

int parent[MAX_N];
int ranka[MAX_N];
void init(int n){
	for(int i=0;i<n;i++){
		parent[i]=i;
		ranka[i]=0;
	}
}
int Find(int x){
	if(parent[x]==x){
    return x;
  }else{
		parent[x]=Find(parent[x]);
		return parent[x];
	}
}
void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x==y)return;
	if(ranka[x]<ranka[y]){
    parent[x]=y;
  }else{
		parent[y]=x;
		if(ranka[x]==ranka[y])ranka[x]++;
	}
}
bool same(int x,int y){
	return Find(x)==Find(y);
}

int main(){
  int n;
  cin>>n;
  vector< pair<int,int> > x(n);
  vector< pair<int,int> > y(n);

  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    x[i].first=a;
    x[i].second=i;
    y[i].first=b;
    y[i].second=i;
  }

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  //cout<<x[0].first<<x[0].second<<endl;
  //vector< vector<int> > d(n,vector<int>(n,1000000001));
  vector< pair< int,pair<int,int> > > cost((n-1)*2);
  int j=0;
  for(int i=0;i<n-1;i++){
    int d2=x[i+1].first-x[i].first;
    //d[x[i].second][x[i+1].second]=min(d[x[i].second][x[i+1].second],d2);
    cost[j].first=d2;
    cost[j].second.first=x[i].second;
    cost[j].second.second=x[i+1].second;
    j++;
    d2=y[i+1].first-y[i].first;
    //d[y[i].second][y[i+1].second]=min(d[y[i].second][y[i+1].second],d2);
    cost[j].first=d2;
    cost[j].second.first=y[i].second;
    cost[j].second.second=y[i+1].second;
    j++;
    //cout<<d[x[i].second][x[i+1].second]<<endl;
    //cout<<d[y[i].second][y[i+1].second]<<endl;
  }
  sort(cost.begin(),cost.end());
  //for(int i=0;i<(n-1)*2;i++)cout<<cost[i].first<<" "<<cost[i].second.first<<" "<<cost[i].second.second<<endl;
  init(n);
  int ans=0;
  for(int i=0;i<(n-1)*2;i++){
    if(!same(cost[i].second.first,cost[i].second.second)){
      Union(cost[i].second.first,cost[i].second.second);
      ans+=cost[i].first;
    }
  }
  cout<<ans<<endl;
  return 0;
}
