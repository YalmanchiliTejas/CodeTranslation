#include <bits/stdc++.h>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}


vector<vector<bool>> connect(8,vector<bool>(8,false));
int dfs(int now,int n,vector<bool> visited){
    bool all_visited = true;
    rep(i,0,n){
        if(visited[i]==false) all_visited=false;
    }
    if(all_visited)return 1;
    int ans=0;
    rep(i,0,n){
        if(connect[now][i]==false || visited[i])continue;
        visited[i]=true;
        ans+=dfs(i,n,visited);
        visited[i]=false;
    }
    return ans;
}
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> a(m),b(m);
    rep(i,0,m){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        connect[a[i]][b[i]]=connect[b[i]][a[i]]=true;
    }
    vector<bool> visited(n,false);
    visited[0]=true;
    cout<<dfs(0,n,visited)<<endl;
    return 0;
}