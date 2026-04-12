#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
vint G[111111];

int deg[1111111];
bool used[111111];

signed main(){
    cin>>N;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    rep(i,N)deg[i]=G[i].size();
    queue<int>que;
    rep(i,N)if(deg[i]==1){
        que.push(i);
    }

    while(que.size()){
        int v=que.front();
        used[v]=true;
        que.pop();
        for(auto u:G[v]){
            if(!used[u]){
                v=u;
                break;
            }
        }

        used[v]=true;
        for(auto u:G[v]){
            if(used[u])continue;
            if(deg[u]==1){
                puts("First");
                return 0;
            }
            deg[u]--;
            if(deg[u]==1){
                que.push(u);
            }
        }
    }

    puts("Second");
    return 0;
}
