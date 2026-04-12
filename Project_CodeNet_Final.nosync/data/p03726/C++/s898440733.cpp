#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}


typedef vector<int> V;
typedef vector<V> Graph;
Graph g(112345);
bool res=false;

int dfs(int v,int p){
    int ans=0;
    for(auto &u:g[v])
        if(p!=u){
            int latte=dfs(u,v);
            if(latte==0){
                if(ans==1)res=true;
                else ans=1;
            }
        }
    return ans;
}
int main(){
    int N;
    cin>>N;
    V c(N+1,0);
    REP(i,N-1){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int latte=dfs(1,1);
    if(latte==0)res=true;
    if(res)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}
