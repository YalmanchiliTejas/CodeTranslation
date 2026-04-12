#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<int,int>;
const ll INF=1LL<<30;
const ll LINF=1LL<<60;
const double eps=1e-5;
const ll MOD=1000000007LL;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
vector<vector<int>> G;
vector<int> c,vis,s;
int main(){
    int n;cin>>n;
    G.resize(n);
    c.resize(n);
    vis.resize(n);
    s.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;--u;--v;
        G[u].push_back(v);
        G[v].push_back(u);
        c[u]++;c[v]++;
    }
    stack<int> st;
    for(int i=0;i<n;i++){
        if(c[i]==1){
            st.push(i);
        }
    }
    while(!st.empty()){
        int v=st.top();st.pop();
        if(vis[v])continue;
        vis[v]=1;
        int to=-1;
        for(auto e:G[v]){
            if(!vis[e]){
                to=e;
            }
        }
        if(to==-1)continue;
        s[v]=1;
        c[to]--;
        s[to]=1;
        vis[to]=1;
        for(auto e:G[to]){
            if(!vis[e]){
                c[e]--;
                if(c[e]==1){
                    st.push(e);
                }
            }
        }
    }
    bool res=false;
    for(int i=0;i<n;i++){
        if(s[i]==0)res=true;
    }
    if(res){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
}
