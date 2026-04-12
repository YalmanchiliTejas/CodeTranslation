#include<bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i=0; i<n; i++)
#define forsn(i, s, n) for(int i=s; i<n; i++)
int n;
vector<pair<pair<int, int>, int > > accx;
vector<pair< pair<int, int>, int > > accy;
vector< pair< int,  pair<int, int> > > edgeset;
//vector< vector<pair<int, int> > > graph;
vector<int> par;
vector<int> size;
long long int weight=0;
int find(int x){
	if(par[x]==-1) return x;
	return par[x]=find(par[x]);
}
void join(int a, int b, int w){
	int para, parb;
	para=find(a); parb=find(b);
	if(para==parb) return;
	if(size[para]<size[parb]) swap(para, parb);
	size[para]+=size[parb];
	par[parb]=para;
	weight+=w;
}
int main(){
	cin>>n;
	forn(i, n){
		int x, y;
		cin>>x>>y;
		accx.push_back(make_pair(make_pair(x, y), i));
		accy.push_back(make_pair(make_pair(y, x), i));
	}
	par.assign(n, -1);
	size.assign(n, 1);
	sort(accx.begin(), accx.end());
	forn(i, n-1){
		edgeset.push_back(make_pair( abs(accx[i].first.first-accx[i+1].first.first) , make_pair(accx[i].second, accx[i+1].second)));
		//graph[accx[i].second].push_back(make_pair(accx[i+1].second, ));
		//graph[accx[i+1].second].push_back(make_pair(accx[i].second, abs(accx[i].first.first-accx[i+1].first.first)));
	}
	sort(accy.begin(), accy.end());
	forn(i, n-1){
		//graph[accx[i].second].push_back(make_pair(accx[i+1].second, abs(accx[i].first.second-accx[i+1].first.second)));
		//graph[accx[i+1].second].push_back(make_pair(accx[i].second, abs(accx[i].first.second-accx[i+1].first.second)));
		edgeset.push_back(make_pair( abs(accy[i].first.first-accy[i+1].first.first) , make_pair(accy[i].second, accy[i+1].second)));
	}
	sort(edgeset.begin(), edgeset.end()) ;
	int len=edgeset.size();
	forn(i, len){
		join(edgeset[i].second.first, edgeset[i].second.second, edgeset[i].first);
	}
	cout<<weight<<endl;		
}