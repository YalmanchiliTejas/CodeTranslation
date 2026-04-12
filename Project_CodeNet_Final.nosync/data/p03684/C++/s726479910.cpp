#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)


struct listGraph{
    int N;
    vector<pair<ll,int>> *edge;

    listGraph(int n){
        N=n;
        edge=new vector<pair<ll,int>>[N];
    }

    void append(int a,int b,ll w){
        //無向グラフ
        edge[a].push_back(make_pair(w,b));
        edge[b].push_back(make_pair(w,a));
        //有向グラフ
        //edge[a].push_back(make_pair(w,b));
    }

    void clear(){
        delete[] edge;
    }

    pair<int,int> longest_path(int s){
        bool *done=new bool[N];
        int u,l2,l=0;
        for(int i=0;i<N;i++) done[i]=false;
        done[s]=true;
        queue<int> q;
        q.push(s);
        l2=1;
        while(true){
            for(int i=0;i<l2;i++){
                for(int j=0;j<edge[q.front()].size();j++){
                    if(done[edge[q.front()][j].second]) continue;
                    done[edge[q.front()][j].second]=true;
                    q.push(j);
                    u=j;
                }q.pop();
            }
            l2=q.size();
            if(l2==0) break;
            l++;
        }
        delete[] done;
        return make_pair(u,l);
    }

    int diag(){//グラフの直径
        pair<int,int> p;
        p=longest_path(0);
        p=longest_path(p.first);
        return p.second;
    }

    ll *dijkstra(int s){
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
        bool *done=new bool[N];
        ll *val=new ll[N];
        for(int i=0;i<N;i++) val[i]=-1;
        val[s]=0;
        q.push(make_pair(0,s));
        pair<ll,int> p;
        for(int num=0;num<N;num++){
            while(true){
                p=q.top();
                q.pop();
                if(done[p.second]) continue;
                done[p.second]=true;
                val[p.second]=p.first;
                break;
            }
            for(int i=0;i<edge[p.second].size();i++){
                if(done[edge[p.second][i].second])continue;
                q.push(make_pair(val[p.second]+edge[p.second][i].first,edge[p.second][i].second));
            }
        }
        delete[] done;
        return val;
    }
   
    ll prim(){
        int s=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<int,int>>> q;
        bool *done=new bool[N];
        for(int i=0;i<N;i++) done[i]=false;
        ll val=0;
        q.push(make_pair(0,s));
        pair<ll,int> p;
        for(int num=0;num<N;num++){
            while(true){
                p=q.top();
                q.pop();
                if(done[p.second]) continue;
                done[p.second]=true;
                val+=p.first;
                break;
            }
            for(int i=0;i<edge[p.second].size();i++){
                if(done[edge[p.second][i].second])continue;
                q.push(make_pair(edge[p.second][i].first,edge[p.second][i].second));
            }
        }
        delete[] done;
        return val;
    }
};

int main(){
    int N;
    cin>>N;
    pair<ll,int> p,q;
    vector<pair<ll,int>> x,y;
    rep(i,N){
        cin>>p.first>>q.first;
        p.second=i;q.second=i;
        x.push_back(p);y.push_back(q);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    listGraph G(N);
    rep(i,N-1){
        G.append(x[i].second,x[i+1].second,x[i+1].first-x[i].first);
        G.append(y[i].second,y[i+1].second,y[i+1].first-y[i].first);
    }

    cout<<G.prim()<<endl;

    return 0;
}