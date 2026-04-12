#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct edge{int to,cost;};

template<typename T> class TreeDPRerooting
{
    using Func=function<T(T,T)>;
    vector<vector<edge>> G;
    int N;
    Func merge,lift;
    T e; // identity element

public:
    vector<vector<T>> sumL,sumR;
    vector<T> dp,res;

    TreeDPRerooting(vector<vector<edge>> G,Func merge,Func lift,T e):
        G(G),merge(merge),lift(lift),e(e),N(G.size()),dp(N),sumL(N),sumR(N),res(N)
    {
        dfs(0,-1);
        reroot(0,-1);
    } 

    T dfs(int v,int par)
    {
        // TreeDP
        T res=e;
        for(edge e:G[v]) if(e.to!=par){
            res=merge(res,lift(dfs(e.to,v),e.cost));
        }
        return dp[v]=res;
    }

    void reroot(int v,int par)
    {
        // accumulate children's information from left and right
        sumL[v].assign(G[v].size()+1,e);
        sumR[v].assign(G[v].size()+1,e);

        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            sumL[v][i+1]=merge(sumL[v][i],lift(dp[e.to],e.cost));
        }
        for(int i=G[v].size()-1;i>=0;i--){
            edge e=G[v][i];
            sumR[v][i]=merge(sumR[v][i+1],lift(dp[e.to],e.cost));
        }

        // calculate res[v] using children's information(L[v],R[v],dp)
        res[v]=sumR[v][0];

        // reroot v with its children
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(e.to!=par){
                int tmp=dp[v];
                dp[v]=merge(sumL[v][i],sumR[v][i+1]);
                reroot(e.to,v);
                dp[v]=tmp;
            }
        }
    }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin>>N;
    vector<vector<edge>> G(N);
    for(int i=0;i<N-1;i++){
        int a,b,c; cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    auto merge=[](int a,int b){
        return max(a,b);
    };
    auto lift=[](int a,int cost){
        return a+cost;
    };
    TreeDPRerooting<int> treedp(G,merge,lift,0LL);
    vector<int> dp=treedp.res;
    for(int i=0;i<N;i++){
        cout<<dp[i]<<endl;
    }
    return 0;
}

