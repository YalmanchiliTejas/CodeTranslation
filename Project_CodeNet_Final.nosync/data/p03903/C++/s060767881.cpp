#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <set>
#include <iomanip>
#include <deque>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define iREP(i,Itr) for(auto (i)=(Itr).begin();(i)!=(Itr).end();(i)++)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
#define UNIQUE(Itr) sort((Itr).begin(),(Itr).end()); (Itr).erase(unique((Itr).begin(),(Itr).end()),(Itr).end())
#define LBOUND(Itr,val) lower_bound((Itr).begin(),(Itr).end(),(val))
#define UBOUND(Itr,val) upper_bound((Itr).begin(),(Itr).end(),(val))
typedef long long ll;

int maxcost[4010][4010];
bool used[4010];
vector<int> G[4010];
int cost[4010][4010];

class UnionFindFixed{
    vector<int> data;
public:
    UnionFindFixed(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

void dfs(int v, int mcost,int ori){
    stack< pair<int,int> > sta; sta.push(make_pair(v,mcost));
    while(sta.size()!=0){
        int vt=sta.top().first;
        int costt=sta.top().second;
        sta.pop();
        used[vt]=true;
        REP(i,G[vt].size()){
            if(!used[G[vt][i]]){
                costt=max(costt,cost[vt][G[vt][i]]);
                maxcost[ori][G[vt][i]]=costt;
                maxcost[ori][G[vt][i]]=costt;
                sta.push(make_pair(G[vt][i],costt));
            }
        }
    }
}

int main(){
    
    int N,M; cin>>N>>M;
    vector< pair<int,pair<int,int> > > v(M);
    REP(i,M)cin>>v[i].second.first>>v[i].second.second>>v[i].first;
    sort(v.begin(),v.end());
    
    ll totalcost=0;
    UnionFindFixed inst(4010);
    REP(i,M){
        int a=v[i].second.first,b=v[i].second.second,c=v[i].first;
        if(!inst.findSet(a,b)){
            inst.unionSet(a,b);
            G[a].push_back(b);
            G[b].push_back(a);
            cost[a][b]=cost[b][a]=c;
            totalcost+=c;
        }
    }
    
    for(int i=1;i<=N;i++){
        REP(j,4010)used[j]=false;
        dfs(i,0,i);
    }
    
    /* for(int i=1;i<=N;i++){
     for(int j=1;j<=N;j++)cout<<maxcost[i][j]<<" ";
     cout<<endl;
     }*/
    
    int Q; cin>>Q;
    REP(i,Q){
        int S,T; cin>>S>>T;
        cout<<totalcost-maxcost[S][T]<<endl;
    }
    
    return 0;
}