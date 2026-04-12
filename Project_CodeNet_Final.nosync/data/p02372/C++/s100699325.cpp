#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+9;
const int inf=INT_MAX;
vector<pair<int, int> >adj[MAX];
void dijikstra(int s, int d[]){
	multiset<pair<int,int> >q;
	d[s]=0;
	q.insert(make_pair(d[s],s));
	while(!q.empty()){
		pair<int, int>p=*q.begin();
		int u=p.second;
		q.erase(q.begin());
		for(int i=0;i<adj[u].size();i++){
			if(d[adj[u][i].first]>d[u]+adj[u][i].second){
				d[adj[u][i].first]=d[u]+adj[u][i].second;
				q.insert(make_pair(d[adj[u][i].first],adj[u][i].first));
			}
		}

	}
}
int main(){
	int d[MAX],d1[MAX],d2[MAX],i,n,m;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(y,w));
		adj[y].push_back(make_pair(x,w));
	}
	for(int i=0;i<n;i++){
		d[i]=inf;
		d1[i]=inf;
		d2[i]=inf;
	}
	dijikstra(0,d);
	int l1,l2,mx=INT_MIN;
	for(int i=0;i<n;i++){
		if(mx<d[i]){
			l1=i;
			mx=d[i];
		}
	}
	dijikstra(l1,d1);
	mx=INT_MIN;
	for(int i=0;i<n;i++){
		if(mx<d1[i]){
			mx=d1[i];
			l2=i;
		}
	}
	dijikstra(l2,d2);
	for(int i=0;i<n;i++){
		cout<<max(d1[i],d2[i])<<"\n";
	}

}
