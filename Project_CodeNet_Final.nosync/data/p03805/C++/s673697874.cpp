#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int edge[8][8];
int reached[8];
int ctr;
int n,m;
int ans;

void dfs(int p){
    if(ctr==n-1){
        ++ans;
        return;
    }
    rep(i,n){
        if(reached[i])continue;
        if(edge[p][i]){
            reached[i]=1;
            ctr++;
            dfs(i);
            reached[i]=0;
            ctr--;
        }
    }
}

int main(){
    cin>>n>>m;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        edge[a-1][b-1]=1;
        edge[b-1][a-1]=1;
    }
    reached[0]=1;
    dfs(0);
    cout<<ans<<endl;
}
