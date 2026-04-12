#include <bits/stdc++.h>
#define rep(i,n) REP(i,0,n)
#define int long long
#define REP(i,l,r) for(int i=l;i<r;i++)
using namespace std;
typedef pair<int,int> P;
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
struct edge{
    int to,cost;
};
class dijkstra{
    int V;
    int d[100002];
    priority_queue<P,vector<P>,greater<P>>que;
    void update(int s,vector<edge> G[]){
        fill(d,d+V+1,100000000000ll);
        d[s]=0;
        que.push(make_pair(0,s));
        while(!que.empty()){
            P p=que.top();
            que.pop();
            int v=p.second;
            if(d[v]<p.first)continue;
            rep(i,G[v].size()){
                edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    que.push(make_pair(d[e.to],e.to));
                }
            }
        }
    }
public:
    dijkstra(int v,int s,vector<edge> G[]){
        V=v;
        update(s,G);
    }
    int find(int e){
        return d[e];
;    }
};
signed main(){
    int n,ans=0;
    int h[20];
    cin>>n;
    rep(i,n){
        cin>>h[i];
        rep(j,i){
            if(h[i]<h[j])goto ioi;
        }
        ans++;
        ioi:;
    }
    cout<<ans<<endl;
}

