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
class Union_Find{
private:
    vector<int> t,s;
public:
    Union_Find(int max_length){
        rep(i,max_length+1){
            t.push_back(i);
            s.push_back(1);
        }
    }
    void Union(int x,int y){
        if(same(x,y))return;
        int tx=Find(x),ty=Find(y);
        if(s[tx]<s[ty]){
            s[ty]+=s[tx];
            t[tx]=ty;
        }
        else if(s[tx]>s[ty]){
            s[tx]+=s[ty];
            t[ty]=tx;
        }
        else if(tx>ty){
            t[tx]=ty;
            s[ty]+=s[tx];
        }
        else{
            t[ty]=tx;
            s[tx]+=s[ty];
        }
    }
    int Find(int n){
        if(t[n]==n)return n;
        else return t[n]=Find(t[n]);
    }
    bool same(int x,int y){
        return Find(x)==Find(y);
    }
    int get_Size(int a){
        return s[a];
    }
};
signed main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    rep(i,n){
        if(s[i]!=s[k-1])cout<<'*';
        else cout<<s[i];
    }
    cout<<endl;
}