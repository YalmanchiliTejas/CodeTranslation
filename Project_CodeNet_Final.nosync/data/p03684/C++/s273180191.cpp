/*
sort points by x (1st time)
			by y (2nd time)
each time => push back the weight bw 2 points
=> MST (kruskal)
=> DONE!			
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N=1e5+5;
struct data{
    int x,y,id;
} c[N];
int n,pset[N],ans;
vector< pair< int,pair<int,int> > > edge;

bool cmpx(data _a,data _b){
    if(_a.x!=_b.x) return _a.x<_b.x;
    else return _a.y<_b.y;
}
bool cmpy(data _a,data _b){
    if(_a.y!=_b.y) return _a.y<_b.y;
    else return _a.x<_b.x;
}

int findset(int pos){
    return ( pos==pset[pos]?pos:pset[pos]=findset(pset[pos]) );
}

bool sameset(int i,int j){
    return findset(i)==findset(j);
}

void unionset(int i,int j){
    pset[findset(i)]=findset(j);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; ++i){
    cin >> c[i].x >> c[i].y;
	c[i].id = i;
	}
    sort(c + 1 , c + n + 1 ,cmpx);
    for(int i = 1; i < n; ++i) edge.push_back(make_pair(c[i+1].x-c[i].x,make_pair(c[i+1].id,c[i].id)));
    sort(c + 1, c + n + 1, cmpy);
    for(int i = 1; i < n; ++i) edge.push_back(make_pair(c[i+1].y-c[i].y,make_pair(c[i+1].id,c[i].id)));
    sort(edge.begin(),edge.end());
    for(int i = 1; i <= n; ++i) pset[i]=i;
    for(int i = 0; i < edge.size(); ++i){
        int w = edge[i].first, u = edge[i].second.first, v = edge[i].second.second;
        if(!sameset(u,v)){
            ans += w;
            unionset(u,v);
        }
    } 
    cout << ans;
    return 0;
}