#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using P = pair<int,int>;

bool visited[100];
int previous[100];
bool edge[100][100];//[from][to]

int given[100];
int n,m;

void dfs1(int current, int pre){
    // cout<<"dfs1 "<<current<<endl;
    previous[current]=pre;
    visited[current]=true;
    for(int next=0;next<n;next++){
        if(edge[next][current]&&!visited[next]){
            dfs1(next,current);
        }
    }
    return;
}

void dfs2(int current, int pre){
    // cout<<"dfs2 "<<current<<endl;
    previous[current]=pre;
    visited[current]=true;
    for(int next=0;next<n;next++){
        if(edge[current][next]&&!visited[next]){
            dfs2(next,current);
        }
    }
    return;
}

void rev1(int s, int t){
    while(t!=s){
        int pre=previous[t];
        edge[t][pre]=false;
        edge[pre][t]=true;
        t=pre;
    }
}

void rev2(int s, int t){
    while(t!=s){
        int pre=previous[t];
        edge[t][pre]=true;
        edge[pre][t]=false;
        t=pre;
    }
}

int main(){
    while(cin>>n>>m,n){
        set<P> mote;//????????£?????°,id
        fill(edge[0],edge[100],false);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--;v--;
            if(i&1){
                edge[u][v]=true;
            }else{
                edge[v][u]=true;
            }
        }
        fill(given,given+100,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) given[i]+=edge[j][i];
            mote.insert(P(given[i],i));
        }
        bool ub=false,lb=false;//?????????????????£??????ture
        while(!(ub&&lb)){
            if(!ub){
                auto ite = mote.end();
                ite--;
                int start = ite->second;
                fill(visited,visited+100,false);
                fill(previous,previous+100,-1);
                dfs1(start,-1);
                int terminal=-1;
                for(int i=0;i<n;i++){
                    if(!visited[i])continue;
                    if(terminal==-1||given[i]<given[terminal]){
                        terminal=i;
                    }
                }
                if(terminal==-1||given[start]-given[terminal]<2){
                    ub=true;
                }else{
                    // cout<<'A'<<endl;
                    rev1(start,terminal);
                    mote.erase(P(given[start],start));
                    mote.erase(P(given[terminal],terminal));
                    given[start]--;
                    given[terminal]++;
                    mote.insert(P(given[start],start));
                    mote.insert(P(given[terminal],terminal));
                    lb=false;
                }
            }
            if(!lb){
                int start = mote.begin()->second;
                fill(visited,visited+100,false);
                fill(previous,previous+100,-1);
                dfs2(start,-1);
                int terminal=-1;
                for(int i=0;i<n;i++){
                    if(!visited[i])continue;
                    if(terminal==-1||given[i]>given[terminal]){
                        terminal=i;
                    }
                }
                if(terminal==-1||given[terminal]-given[start]<2){
                    lb=true;
                }else{
                    // cout<<'B'<<endl;
                    rev2(start,terminal);
                    mote.erase(P(given[start],start));
                    mote.erase(P(given[terminal],terminal));
                    given[start]++;
                    given[terminal]--;
                    mote.insert(P(given[start],start));
                    mote.insert(P(given[terminal],terminal));
                    ub=false;
                }
            }
        }
        int low=101,high=-1;
        for(int i=0;i<n;i++){
            low=min(low,given[i]);
            high=max(high,given[i]);
        }
        cout<<low<<' '<<high<<endl;
    }
}