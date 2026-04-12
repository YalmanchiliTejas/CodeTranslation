#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<type_traits>
#include<math.h>
#include<fstream>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7; 

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define out(str) cout << str << endl
#define ALL(a) (a).begin(),(a).end()
#define INF_INT (1<<30)
#define INF_LL (1ll<<62)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int N,M,a,b;
bool G[10][10];

int dfs(int now, bool passed[]){
    passed[now]=true;

    bool done=true;
    rep(i,N){
        if(!passed[i])done=false;
    }
    if(done)return 1;

    int ans = 0;

    rep(next,N){
        if(passed[next])continue;
        if(G[now][next]){
            passed[next]=true;
            ans+=dfs(next,passed);
            passed[next]=false;
        }
    }

    return ans;
}

int main(){
    cin>>N>>M;
    rep(i,10){
        rep(j,10)G[i][j]=false;
    }
    rep(i,M){
        cin>>a>>b;
        a--;
        b--;
        G[a][b]=true;
        G[b][a]=true;
    }
    // rep(i,10){
    //     rep(j,10){
    //         cout<<G[i][j];
    //     }
    //     out("");
    // }
    bool aaaa[N];
    rep(i,N)aaaa[i]=false;
    aaaa[0]=true;
    out(dfs(0,aaaa));

    
    
}