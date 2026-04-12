#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
#define MOD 1000000007
vector <ll> g[10];
ll visited[10];
ll dfs(ll v,ll N){
    ll i;
    bool flag=1;
    for(i=0;i<N;i++){
        if(visited[i]==0)flag=0;
    }
    if(flag)return 1;
    ll cnt=0;
    for(auto itr=g[v].begin();itr!=g[v].end();++itr){
        if(visited[*itr]==0){
            visited[*itr]=1;
            cnt+=dfs(*itr,N);
            visited[*itr]=0;
        }
    }
    return cnt;
}
int main(){
    ll N,M;
    cin >> N >> M;
    ll i,a,b;
    for(i=0;i<N;i++){
        visited[i]=0;
    }
    for(i=0;i<M;i++){
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    visited[0]=1;
    cout << dfs(0,N)<<endl;
    return 0;
}
