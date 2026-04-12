#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M,ans;
const ll nmax=8;
const ll mmax=8*(8-1)/2;
ll graph[nmax+1][nmax+1];
bool visited[nmax],allvisited;

void dfs(ll c){
    allvisited=true;
//    cout<<N<<" "<<M<<endl;
    for(ll i=1;i<=N;i++){
        if(!visited[i]){
            allvisited=false;
            break;
        }
    }
    if(allvisited){
//        cout<<"aaa"<<endl;
        ans++;
        //return;
    }
    for(ll i=1;i<=N;i++){
        if(graph[c][i]==1&&(!visited[i])){
            visited[i]=true;
            dfs(i);
            visited[i]=false;
        }
    }
}

int main(){
    cin>>N>>M;
    ll a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        graph[a][b]=graph[b][a]=1;
    }
    visited[1]=true;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
