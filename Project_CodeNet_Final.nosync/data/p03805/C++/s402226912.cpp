#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll LongINF=1e13+7;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template <class T, class Y>T GCD(T a, Y b){if(a<b){int c=a;a=b;b=c;}if (a % b == 0){return b;}return GCD(b, a % b);}
void clear(queue<pair<int, int>> &q){queue<pair<int, int>> empty;swap(q, empty);} //queueの中身の型は適時変更を忘れない

#define rep(i,n) for(int i=0;i<(n);i++)
int N,M;
using Graph=vector<vector<int> >;

int DFS(int v,vector<bool> visited,Graph &G){

    bool all=true;

    for(int i=0;i<N;i++){
        if(visited[i]==false)all=false;
    }

    if(all)return 1;
    int ret=0;

    for(auto x:G[v]){
        if(visited[x])continue;
        visited[x]=true;
        ret+=DFS(x,visited,G);
        visited[x]=false;
    }
    return ret;
}

int main(){
    cin>>N>>M;
    Graph G(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> visited(N,false);
    visited[0]=true;

    cout<<DFS(0,visited,G)<<endl;

    return 0;
}

//a=97,z=122