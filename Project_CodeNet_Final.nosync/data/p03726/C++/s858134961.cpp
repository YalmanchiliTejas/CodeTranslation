#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

bool visited[100001];
vector<int> E[100001];
int black=0,white=0;

bool isBlack(int v){
    visited[v]=true;
    if(E[v].size()==1&&visited[E[v][0]]){
        ++black;
        return true;
    }
    bool hasBlack=false;
    for(int u:E[v])if(!visited[u])if(isBlack(u))hasBlack=true;
    if(hasBlack)++white;
    else ++black;
    return !hasBlack;
}

int main(){
    int N;cin>>N;

    REP(i,N-1){
        int a,b;cin>>a>>b;
        E[--a].push_back(--b);
        E[b].push_back(a);
    }
    fill_n(visited,N+1,false);
    isBlack(0);

    if(black>white){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }



    return 0;
}